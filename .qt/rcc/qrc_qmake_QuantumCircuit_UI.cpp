/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.7.3
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /Users/James/GitHub/quantum-circuit/QuantumCircuit/UI/qmldir
  0x0,0x0,0x0,0x58,
  0x6d,
  0x6f,0x64,0x75,0x6c,0x65,0x20,0x51,0x75,0x61,0x6e,0x74,0x75,0x6d,0x43,0x69,0x72,
  0x63,0x75,0x69,0x74,0x2e,0x55,0x49,0xa,0x74,0x79,0x70,0x65,0x69,0x6e,0x66,0x6f,
  0x20,0x71,0x75,0x61,0x6e,0x74,0x75,0x6d,0x5f,0x63,0x69,0x72,0x63,0x75,0x69,0x74,
  0x2e,0x71,0x6d,0x6c,0x74,0x79,0x70,0x65,0x73,0xa,0x70,0x72,0x65,0x66,0x65,0x72,
  0x20,0x3a,0x2f,0x51,0x75,0x61,0x6e,0x74,0x75,0x6d,0x43,0x69,0x72,0x63,0x75,0x69,
  0x74,0x2f,0x55,0x49,0x2f,0xa,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // QuantumCircuit
  0x0,0xe,
  0x1,0x3,0xce,0x24,
  0x0,0x51,
  0x0,0x75,0x0,0x61,0x0,0x6e,0x0,0x74,0x0,0x75,0x0,0x6d,0x0,0x43,0x0,0x69,0x0,0x72,0x0,0x63,0x0,0x75,0x0,0x69,0x0,0x74,
    // UI
  0x0,0x2,
  0x0,0x0,0x5,0x99,
  0x0,0x55,
  0x0,0x49,
    // qmldir
  0x0,0x6,
  0x7,0x84,0x2b,0x2,
  0x0,0x71,
  0x0,0x6d,0x0,0x6c,0x0,0x64,0x0,0x69,0x0,0x72,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/QuantumCircuit
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/QuantumCircuit/UI
  0x0,0x0,0x0,0x22,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/QuantumCircuit/UI/qmldir
  0x0,0x0,0x0,0x2c,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x94,0x70,0x91,0x3,0xba,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_QuantumCircuit_UI)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_QuantumCircuit_UI)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_QuantumCircuit_UI)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_QuantumCircuit_UI)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_QuantumCircuit_UI)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_QuantumCircuit_UI)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
