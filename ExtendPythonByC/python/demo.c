#define PY_SSIZE_T_CLEAN
#include <Python.h>
static PyMethodDef SpamMethods[] = {
    
    {"system",  system, METH_VARARGS,
     "Execute a shell command."},
    
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    "spam_doc", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};


static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    // const char *command;
    // int sts;

    // if (!PyArg_ParseTuple(args, "s", &command))
    //     return NULL;
    // sts = system(command);
    // return PyLong_FromLong(sts);
       const char* name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}

PyMODINIT_FUNC PyInit_spam(void)
{
    return    PyModule_Create(&SpamMethods);
}