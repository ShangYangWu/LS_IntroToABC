#include "base/abc/abc.h"
#include "pa1.h"

ABC_NAMESPACE_HEADER_START

// static int PA1_Command(Abc_Frame_t * pAbc, int argc, char **argv);

// void PA1_Init(Abc_Frame_t * pAbc){
//     Cmd_CommandAdd(pAbc, "Various", "pa1", PA1_Command, 0);
// }

// int PA1_Command(Abc_Frame_t * pAbc, int argc, char **argv){
//     int fVerbose;
//     int c, result;
//     fVerbose = 0;
//     Extra_UtilGetoptReset();
//     while((c = Extra_UtilGetopt(argc, argv, "wh")) != EOF){
//         switch (c)
//         {
//         case 'v':
//             fVerbose ^= 1;
//             break;
        
//         case 'h':
//             goto usage;

//         default:
//             goto usage;
//         }
//     }

//     result = PA1_FunctionAbc(pAbc);

//     if(fVerbose){
//         Abc_Print(1, "\nVerbose node is on.\n");
//         if(result){
//             Abc_Print(1, "The command finished successfully.\n");
//         }else{
//             Abc_Print(1, "The command execution has failed.\n");
//         }
//     }

//     return 0;

//     usage:
//         Abc_Print(-2, "usage: firstcmd [-vh]\n");
//         Abc_Print(-2, "\t First command in ABC\n");
//         Abc_Print(-2, "\t-v : toggle printing verbose information [default = %s]\n", fVerbose ? "yes" : "no");
//         Abc_Print(-2, "\t-h : print the command usage\n");
//         return 1;

// }


static int PA1_Command(Abc_Frame_t *pAbc, int argc, char **argv);

void PA1_Init(Abc_Frame_t *pAbc)
{
    Cmd_CommandAdd(pAbc, "Various", "iteratentk", PA1_Command, 0);
}

int PA1_Command(Abc_Frame_t *pAbc, int argc, char **argv)
{
    Iteratentk(pAbc);
    return 0;
}

ABC_NAMESPACE_HEADER_END