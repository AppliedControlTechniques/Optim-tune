# Optim-tune
Gain tuning method for 2-parameter controllers, 5% tolerance, 48 iterations

See the manual in the PDF file (Gaintuner_method.pdf) for further info. 

In the repository you can find both Matlab version as well as a code-generated C++ version with the sample syntax


// includes for MATLAB-generated code

        #include "update_parameters_FIB.h"

////////////////////////////////////////////////////////////////////////

// number of steps to collect performance index J (incremented)

        double N_c = 50;
        
// number of steps to complete a single iteration

        double N_max = 60;
        
// initial value of the second parameter during the half of the first bootstrap

        double Par_initial = 1;
        
// method for gaintuner (see manual)
        
        double method = 2;
        
// comments for gaintuner (see manual)

        double comments = 0;
        double output_FIB[4];

// double P1_range[2];
// double P2_range[2];

        double gain1;
        double gain2;

        double control_error;
        double main_iteration_counter = 0;

// put the following in the tuning loop

        update_parameters_FIB(control_error, main_iteration_counter, P1_range, P2_range, N_c, N_max, Par_initial, method, comments, output_FIB);

        gain1 = output_FIB[0];
        gain2 = output_FIB[1];
        perf  = output_FIB[2];
        main_iteration_counter = output_FIB[3];

**********************

In case of any comments, do not hesitate to contact us. 

The authors take no responsibility for using this software, no claims may be issued towards us for potential losses and harms. You use the software at your own risk. 

Dariusz Horla, Wojciech Giernacki
Poznan University of Technology
dhorla.put.poznan.pl
act.put.poznan.pl

dariusz.horla@put.poznan.pl
