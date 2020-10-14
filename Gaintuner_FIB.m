function output = update_parameters_FIB(input,P1_range,P2_range,N_c,N_max,Par_initial)

output = [0 0 0 0]; % prepare dummy variable
controller_pars = [0,0];

% input                     - incremental value of the performance index
% main_iteration_counter    - iterates from 1 to 48
% P1_range                  - admissible range for the first parameter
% P2_range                  - admissible range for the second parameter
% N_c                       - number of samples to obtain J
% N_max                     - number of samples in a single iteration
% Par_initial               - initial value of the second parameter

N_fib = 6; 	% resulting from a 5% tollerance

indexes_similar_params = -1; % create, if unnecessary (default value)

P_range = [P1_range ; P2_range];  % initial range for the 1st parameter (1st row), and the 2nd parameter (2nd row)

    global information_matrix           % (matrix in which all data is stored)
    global J                            % (current value of the performance index - updated every iteration)
    global iteration                    % (iteration counter, for performance index update, see N_c and N_max)
    global changed_parameter            % ID of the changed parameter (== 1 or 2)
    global main_iteration_counter            % ID of the changed parameter (== 1 or 2)

    global fileID
    
   
if isequal(main_iteration_counter,0) % if the method is launched for the first time
    fileID = fopen('Tuning_results.txt','w');
    fprintf(fileID,'\n*************************************************************')
    fprintf(fileID,'\n (c) Model-free autotuner (2 parameters)                     ')
    fprintf(fileID,'\n     based on zero-order Fibonacci search method             ')
    fprintf(fileID,'\n                            Dariusz Horla, Wojciech Giernacki')
    fprintf(fileID,'\n                            Poznan University of Technology  ')
    fprintf(fileID,'\n                            dariusz.horla@put.poznan.pl      ')
    fprintf(fileID,'\n*************************************************************')
    fprintf(fileID,'\n accuracy of calculations (epsilon) = 0.05')
    fprintf(fileID,'\n no. of bootstrap cycles            = 2')
    fprintf(fileID,'\n total number of main iterations    = 48')
    
    fprintf(fileID,'\n\n')
    fprintf(fileID,'Iter.   Par  |      Par(-)      Par(+) |        Par1        Par2 |      J     ');    
    fprintf(fileID,'\n-------------------------------------------------------------------------------');    
    N_fib = 6;

    information_matrix = zeros(49,7);  % generate empty matrix 

    iteration = 0;                      % iteration counter (J update)
    J = 0;                              % initial value of the performance index
    changed_parameter = 1;              % ID of the changed parameter
    main_iteration_counter = 1;         % main counter, defining rows of the information_matrix
    
    information_matrix(1:2*N_fib,2) = 1;                % change the 1st paramter
    information_matrix(1,1) = 1;                % c hange the 1st paramter

    proposed_range = generate_FIB_range(1,N_fib,P_range(1,1),P_range(1,2));
    
    information_matrix(1,3) = P_range(1,1);    % calculated value (1st row)
    information_matrix(1,4) = P_range(1,2);    % calculated value (1st row)
    information_matrix(2,3) = P_range(1,1);    % calculated value (1st row)
    information_matrix(2,4) = P_range(1,2);    % calculated value (1st row)
    information_matrix(1,5) = proposed_range(1);    % calculated value (1st row)
    information_matrix(2,5) = proposed_range(2);    % calculated value (2nd row)
    information_matrix(1:2*N_fib,6) = Par_initial;    % calculated value
    information_matrix(1,7) = 0;    % value of the performance index
    information_matrix(2,7) = 0;    % value of the performance index

    end % if ~exist('J')
    
    iteration = iteration+1;    % increase the iteration number
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


if (iteration < N_c) % main iteration count, 

    J = J+input;
 
    controller_pars = [information_matrix(main_iteration_counter,5), information_matrix(main_iteration_counter,6)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

elseif (iteration == N_c)  & (main_iteration_counter<3)% measurements have ended, 1st row filled

    J = J+input;

    if mod(main_iteration_counter,2) % 1 == is odd, % 0 == otherwise
            information_matrix(main_iteration_counter,7) = J;
            controller_pars = [information_matrix(main_iteration_counter+1,5), information_matrix(main_iteration_counter+1,6)];
    else
            information_matrix(main_iteration_counter,1) = main_iteration_counter;

            information_matrix(main_iteration_counter,7) = J;
            J_left = information_matrix(main_iteration_counter-1,7);    % odd row (left-hand side in the range)
            J_right = information_matrix(main_iteration_counter,7);     % even row (right-hand side in the range)

            old_range = [information_matrix(main_iteration_counter,3), information_matrix(main_iteration_counter,4)];
            new_range = zeros(1,2);
            
            i = 1;
            
            proposed_range = generate_FIB_range(i,N_fib,old_range(1),old_range(2));

            if J_left<=J_right     % reduce from the right
                 new_range(1) = old_range(1);
                 new_range(2) = proposed_range(2);
             else                   % reduce from the left
                 new_range(1) = proposed_range(1);
                 new_range(2) = old_range(2);
             end

             
             proposed_range = generate_FIB_range(i+1,N_fib,new_range(1),new_range(2));

            information_matrix(main_iteration_counter+1,3) = new_range(1); % odd row (new range, to-be-reduced)
            information_matrix(main_iteration_counter+1,4) = new_range(2);
            information_matrix(main_iteration_counter+2,3) = new_range(1); % even row (new range, to-be-reduced)
            information_matrix(main_iteration_counter+2,4) = new_range(2);

            information_matrix(main_iteration_counter+1,5) = proposed_range(1); % 
            information_matrix(main_iteration_counter+2,5) = proposed_range(2); % 
            controller_pars = [information_matrix(main_iteration_counter+1,5), information_matrix(main_iteration_counter+1,6)];

            
    end
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

elseif (iteration == N_c) & (main_iteration_counter>=3)   % measurements have ended

    
    J = J+input;

       
   if mod(main_iteration_counter,2) % 1 == is odd, % 0 == otherwise
        % 1) store in information_matrix the current value of J
            information_matrix(main_iteration_counter,7) = J;
        % 2) switch to the next row (next controller parameter, right-hand
        % side value parameter in the current range)
            
            
            % if the current row is odd, and in the next iteration (even
            % row) parameters have been already considered, and this is not
            % the last iteration from the bootstrap -- generate new range
            

                    % if indexes_similar_params = -1 the method is either 2
                    % or 0, and no skipping is required
                    
                    
        if indexes_similar_params(1)<0  % if the next combination has not already been considered
            controller_pars = [information_matrix(main_iteration_counter+1,5), information_matrix(main_iteration_counter+1,6)];
        elseif indexes_similar_params(1)>0  % if the next combination has already been considered
            
            % if we are here, it means that the next iteration is not the
            % last one from the bootstrap, and can be skipped
            % OPTIMIZATION IS REQUIRED!!!


            
            
            
                    information_matrix(main_iteration_counter,1) = main_iteration_counter;
                    information_matrix(main_iteration_counter+1,1) = main_iteration_counter+1;
                    information_matrix(main_iteration_counter+1,7) = information_matrix(indexes_similar_params(1),7);
                    J_left = information_matrix(main_iteration_counter,7);    % odd row (left-hand side in the range)
                    J_right = information_matrix(main_iteration_counter+1,7);     % even row (right-hand side in the range)

                    old_range = [information_matrix(main_iteration_counter,3), information_matrix(main_iteration_counter,4)];
                    new_range = zeros(1,2);

                    % PROPOSE THE NEW REDUCED RANGE

                    % current iteration index 1 <= i <= N_fib
                    i = mod(ceil(main_iteration_counter/2),N_fib);

                    proposed_range = generate_FIB_range(i+1,N_fib,old_range(1),old_range(2));

                    % decide how to use it (how to reduce the old range)

                     if J_left<=J_right     % reduce from the right
                         %disp('The range is reduced from the right to:')
                         new_range(1) = old_range(1);
                         new_range(2) = proposed_range(2);
                     else                   % reduce from the left
                         %disp('The range is reduced from the left to:')
                         new_range(1) = proposed_range(1);
                         new_range(2) = old_range(2);
                     end

                    % below: prepare parameters for the next iteration
                    information_matrix(main_iteration_counter+2,3) = new_range(1); % odd row (new range, to-be-reduced)
                    information_matrix(main_iteration_counter+2,4) = new_range(2);
                    information_matrix(main_iteration_counter+3,3) = new_range(1); % even row (new range, to-be-reduced)
                    information_matrix(main_iteration_counter+3,4) = new_range(2);

                    % 3) calculate a pair of values for the next iteration, fill the next two rows

                    % current iteration index 1 <= i <= N_fib

                        % generate two new points for the selected paramter
                        next_range = generate_FIB_range(i+2,N_fib,new_range(1),new_range(2));

                        if isequal(changed_parameter,1)

                            information_matrix(main_iteration_counter+2,5) = next_range(1);
                            information_matrix(main_iteration_counter+3,5) = next_range(2);
                            % columnt 6 is filled at the beginning of main
                            % iteration with the values of the 2nd paramter
                        else
                            information_matrix(main_iteration_counter+2,6) = next_range(1);
                            information_matrix(main_iteration_counter+3,6) = next_range(2);
                            % columnt 5 is filled at the beginning of main
                            % iteration with the values of the 1st paramter
                        end


        end           
                    
   elseif isequal(main_iteration_counter,48) % last call of the algorithm
       information_matrix(main_iteration_counter,7) = J;
       J_left = information_matrix(47,7);
        J_right = information_matrix(48,7);

        old_range = [information_matrix(main_iteration_counter,3), information_matrix(main_iteration_counter,4)];
        new_range = zeros(1,2);

                     if J_left<=J_right     % reduce from the right
                         %disp('The range is reduced from the right to:')
                         new_range(1) = old_range(1);
                         new_range(2) = information_matrix(main_iteration_counter,6);
                     else                   % reduce from the left
                         %disp('The range is reduced from the left to:')
                         new_range(1) = information_matrix(main_iteration_counter-1,6);
                         new_range(2) = old_range(2);
                     end
        optimal_parameter = mean(new_range);
       information_matrix(49,5) = information_matrix(48,5);
       information_matrix(49,6) = optimal_parameter;
  
   else % if mod(main_iteration_counter,2) % 1 == is odd, % 0 == otherwise
       
       
            information_matrix(main_iteration_counter,1) = main_iteration_counter;
        % 1) store in information_matrix the current value of J
            information_matrix(main_iteration_counter,7) = J;
        % 2) decide how to reduce the current range
            J_left = information_matrix(main_iteration_counter-1,7);    % odd row (left-hand side in the range)
            J_right = information_matrix(main_iteration_counter,7);     % even row (right-hand side in the range)

            old_range = [information_matrix(main_iteration_counter,3), information_matrix(main_iteration_counter,4)];
            new_range = zeros(1,2);
            
            % PROPOSE THE NEW REDUCED RANGE
            
            % current iteration index 1 <= i <= N_fib
            i = mod(ceil(main_iteration_counter/2),N_fib);
            
            proposed_range = generate_FIB_range(i,N_fib,old_range(1),old_range(2));
            
            % decide how to use it (how to reduce the old range)
            
             if J_left<=J_right     % reduce from the right
                 %disp('The range is reduced from the right to:')
                 new_range(1) = old_range(1);
                 new_range(2) = proposed_range(2);
             else                   % reduce from the left
                 %disp('The range is reduced from the left to:')
                 new_range(1) = proposed_range(1);
                 new_range(2) = old_range(2);
             end
            
            % below: prepare parameters for the next iteration
            information_matrix(main_iteration_counter+1,3) = new_range(1); % odd row (new range, to-be-reduced)
            information_matrix(main_iteration_counter+1,4) = new_range(2);
            information_matrix(main_iteration_counter+2,3) = new_range(1); % even row (new range, to-be-reduced)
            information_matrix(main_iteration_counter+2,4) = new_range(2);
            
            % 3) calculate a pair of values for the next iteration, fill the next two rows

            % current iteration index 1 <= i <= N_fib
            
                
            if mod(main_iteration_counter,2*N_fib)>0
                % generate two new points for the selected paramter
                next_range = generate_FIB_range(i+1,N_fib,new_range(1),new_range(2));

                        if isequal(changed_parameter,1)

                            information_matrix(main_iteration_counter+1,5) = next_range(1);
                            information_matrix(main_iteration_counter+2,5) = next_range(2);
                            % columnt 6 is filled at the beginning of main
                            % iteration with the values of the 2nd paramter
                        else
                            information_matrix(main_iteration_counter+1,6) = next_range(1);
                            information_matrix(main_iteration_counter+2,6) = next_range(2);
                            % columnt 5 is filled at the beginning of main
                            % iteration with the values of the 1st paramter
                        end

                
                    % IF THE NEXT ROW IS ODD AND ALREADY EVALUATED - SKIP IT!!!

                else % stopping criterion met, prepare the optimal value of the changed_parameter for the next 2*N_fib iterations
                    optimal_parameter = mean(new_range);
                        if isequal(changed_parameter,1)
                              information_matrix(main_iteration_counter+1:main_iteration_counter+2*N_fib,5) = optimal_parameter;
                            changed_parameter = 2;
                            information_matrix(main_iteration_counter+1:main_iteration_counter+2,3) = P_range(2,1);
                            information_matrix(main_iteration_counter+1:main_iteration_counter+2,4) = P_range(2,2);
                            % generate two new inner solutions
                            proposed_range = generate_FIB_range(1,N_fib,P_range(2,1),P_range(2,2));
                            information_matrix(main_iteration_counter+1,6) = proposed_range(1);
                            information_matrix(main_iteration_counter+2,6) = proposed_range(2);
                        else
                            information_matrix(main_iteration_counter+1:main_iteration_counter+2*N_fib,6) = optimal_parameter;
                            changed_parameter = 1;
                            information_matrix(main_iteration_counter+1:main_iteration_counter+2,3) = P_range(1,1);
                            information_matrix(main_iteration_counter+1:main_iteration_counter+2,4) = P_range(1,2);
                            % generate two new inner solutions
                            proposed_range = generate_FIB_range(1,N_fib,P_range(1,1),P_range(1,2));
                            information_matrix(main_iteration_counter+1,5) = proposed_range(1);
                            information_matrix(main_iteration_counter+2,5) = proposed_range(2);


                        end
                        information_matrix(main_iteration_counter+1:main_iteration_counter+2*N_fib,2) = changed_parameter;
            end
            
            
   end  %if mod(main_iteration_counter,2) % 1 == is odd, % 0 == otherwise

	controller_pars = [information_matrix(main_iteration_counter+1,5), information_matrix(main_iteration_counter+1,6)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

elseif (iteration > N_c) & (iteration < N_max) 

    J = 0;
    controller_pars = [information_matrix(main_iteration_counter+1,5), information_matrix(main_iteration_counter+1,6)];
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

elseif (iteration == N_max ) & (main_iteration_counter<=48)
    
    controller_pars = [information_matrix(main_iteration_counter+1,5), information_matrix(main_iteration_counter+1,6)];

   	information_matrix(main_iteration_counter,1) = main_iteration_counter;
   
       fprintf(fileID,'\n%5.0f',information_matrix(main_iteration_counter,1));    
       fprintf(fileID,'  %5.0f',information_matrix(main_iteration_counter,2));    
       fprintf(fileID,' |  %10.4f',information_matrix(main_iteration_counter,3));    
       fprintf(fileID,'  %10.4f',information_matrix(main_iteration_counter,4));    
       fprintf(fileID,' |  %10.4f',information_matrix(main_iteration_counter,5));    
       fprintf(fileID,'  %10.4f',information_matrix(main_iteration_counter,6));    
       fprintf(fileID,' |  %10.4f',information_matrix(main_iteration_counter,7));    
    iteration = 0;
    main_iteration_counter = main_iteration_counter+1;
        J = 0;

        if isequal(mod(main_iteration_counter-1,2*N_fib),0)
                fprintf(fileID,'\n-------------------------------------------------------------------------------');    
                
                
                if isequal(main_iteration_counter,49)
                           controller_pars = [ information_matrix(49,5) information_matrix(49,6)];
       fprintf(fileID,'\n>> The algorithm reached its expected number of iterations (2 bootstraps), terminating');
   
   iteration = 9999;
   J = 0;
   main_iteration_counter = main_iteration_counter +1;

   fprintf(fileID,'\n>> OPTIMAL SOLUTION (Par1,Par2) w.r.t. given tollerance:');
   fprintf(fileID,'\n%14.4f',controller_pars(1));
   fprintf(fileID,'\n%14.4f',controller_pars(2));
   fclose(fileID);

                end
        end
elseif iteration >= 10000 % stopping condition is met

    controller_pars = [information_matrix(49,5), information_matrix(49,6)];
	J = 0;

end

output = [controller_pars(1) controller_pars(2) J];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SUBFUNCTIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function new_range = generate_FIB_range(i,N_max,current_range1,current_range2)

    delta = 0.01;
    
    rho = FIB_number(N_max-i)/FIB_number(N_max-i+2);
    if i==N_max
       dd = delta;
    else
       dd = 0;
    end
    % previous range
    length_old = current_range2-current_range1;
    new_range = [current_range1 + (rho-dd)*length_old, current_range1 + (1-rho+dd)*length_old];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    function FFF = FIB_number(n)

FFF = 0;

if n>0
    F = 0;
    FF = 1;
    
    for i=1:n
        FFF = FF+F;
        F=FF;
        FF=FFF;
    end
else
    FFF = 1;
end