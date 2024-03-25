#include "base/main/main.h"

ABC_NAMESPACE_IMPL_START

// int PA1_Function(Abc_Ntk_t * pNtk);
// int PA1_FunctionAbc(Abc_Frame_t *pAbc);

// int PA1_FunctionAbc(Abc_Frame_t *pAbc){
//     Abc_Ntk_t * pNtk;
//     int result;

//     // Get the read network
//     pNtk = Abc_FrameReadNtk(pAbc);

//     if(pNtk == NULL){
//         Abc_Print(-1, "PA1_FunctionAbc: Getting target network failed.\n");
//         return 0;
//     }

//     // Call the main function
//     result = PA1_Function(pNtk);
    
//     return result;
// }

// int PA1_Function(Abc_Ntk_t * pNtk){
//     // Check if the network is strashed
//     if(!Abc_NtkIsStrash(pNtk)){
//         Abc_Print(-1, "PA1_Function: This command is only applicable to strashed networks.\n");
//         return 0;
//     }

//     // Print information about the network
//     Abc_Print(1, "The network %s has:\n", Abc_NtkName(pNtk));
//     Abc_Print(1, "\t- %d primary inputs;\n", Abc_NtkPiNum(pNtk));
//     Abc_Print(1, "\t- %d primary outputs;\n", Abc_NtkPoNum(pNtk));
//     Abc_Print(1, "\t- %d nodes;\n", Abc_NtkNodeNum(pNtk));
//     return 1;
// };

void Iteratentk_Implement(Abc_Ntk_t *pNtk);

void Iteratentk(Abc_Frame_t *pAbc)
{
    Abc_Ntk_t *pNtk;
    pNtk = Abc_FrameReadNtk(pAbc);

    if (pNtk == NULL)
    {
        Abc_Print(-1, "Failure from pa1.c : Iteratentk\n");
        return;
    }
    Iteratentk_Implement(pNtk);

    return;
}

void Iteratentk_Implement(Abc_Ntk_t *pNtk)
{
    if (!Abc_NtkIsStrash(pNtk))
    {
        Abc_Print(-1, "PA1_Function: This command is only applicable to strashed networks.\n");
        return;
    }

    Abc_Print(1, "<< Print Each Obj- >>\n");
    Abc_Print(1, "ID\tNAME\t\tTYPE\t\tLEVEL\n--------------------------------------------------------\n");

    Abc_Obj_t *pObj = NULL;
    int i;
    Abc_NtkForEachObj(pNtk, pObj, i)
    {
        Abc_Print(1, "Id :%d", pObj->Id);
        Abc_Print(1, "\tName : %s", Abc_ObjName(pObj));
        Abc_Print(1, "\tNodeType : %d", Abc_ObjType(pObj));
        Abc_Print(1, "\tNodeLevel : %d", Abc_ObjLevel(pObj));
        int j;
        Abc_Obj_t *pFanin;
        Abc_ObjForEachFanin(pObj, pFanin, j)
        {
            Abc_Print(1, "\tFiName : %s", Abc_ObjName(pFanin));
            if (j == 0)
                Abc_Print(1, "\tFaninPhase : %d ", pObj->fCompl0);
            else if (j == 1)
                Abc_Print(1, "\tFaninPhase : %d ", pObj->fCompl1);
        }
        Abc_Print(1, "\n");
    }
    Abc_Print(1, "<< ----- END ----- >>\n");
    return;
}

ABC_NAMESPACE_IMPL_END