#include <Python.h>
static PyObject *Extest_fac(PyObject *self, PyObject*args)
{
    int res; //parse result
    int num; //arg for fac()
    PyObject *retval;
    res = PyArg_ParseTuple(args, "i",&num);//转换从python传入的参数为整数
    if(!res)//type error
    {
        return NULL;
    }
    res = fac(num);//函数调用
    retval = (PyObject *)Py_BuildValue("i",res);//将res从c的int类型转换为python对象类型
    return retval;
}    


static PyMethodDef
ExtestMethods[] = {
    {"fac", Extest_fac, METH_VARARGS},
    {"doppel", Extest_doppel, METH_VARARGS},
    {NULL, NULL},
};

initModule() 
void initExtest()
{
    Py_InitModule("Extest", ExtestMethods);
}