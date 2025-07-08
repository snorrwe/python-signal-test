#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <string.h>

volatile PyObject **foo = NULL;

static PyObject *test_segv(PyObject *self, PyObject *args) { return *foo; }

static PyMethodDef k_methods[] = {
    {"test_segv", test_segv, METH_VARARGS, "Cause a segfault"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef test_segv_module = {
    PyModuleDef_HEAD_INIT, "test_segv", "Cause a segfault", -1, k_methods};

PyMODINIT_FUNC PyInit_test_segv(void) {
  return PyModule_Create(&test_segv_module);
}
