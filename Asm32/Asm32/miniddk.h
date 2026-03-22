
#ifndef MINIDDK_H
#define MINIDDK_H

#include <windows.h>

typedef LONG NTSTATUS;

// Generic test for success on any status value (non-negative numbers
// indicate success).

#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

// Unicode strings are counted 16-bit character strings. If they are
// NULL terminated, Length does not include trailing NULL.
//

typedef struct _UNICODE_STRING
    {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
    }
UNICODE_STRING;

typedef UNICODE_STRING* PUNICODE_STRING;
typedef const UNICODE_STRING* PCUNICODE_STRING;

#ifndef UNICODE_NULL
#define UNICODE_NULL ((WCHAR)0)
#endif

// Valid values for the Attributes field

#define OBJ_INHERIT           0x00000002L
#define OBJ_PERMANENT         0x00000010L
#define OBJ_EXCLUSIVE         0x00000020L
#define OBJ_CASE_INSENSITIVE  0x00000040L
#define OBJ_OPENIF            0x00000080L
#define OBJ_OPENLINK          0x00000100L
#define OBJ_KERNEL_HANDLE     0x00000200L
#define OBJ_VALID_ATTRIBUTES  0x000003F2L

// Object Attributes structure

typedef struct _OBJECT_ATTRIBUTES
    {
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR
    PVOID SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE
    }
OBJECT_ATTRIBUTES;

typedef OBJECT_ATTRIBUTES* POBJECT_ATTRIBUTES;

#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );        \
    (p)->RootDirectory = r;                           \
    (p)->Attributes = a;                              \
    (p)->ObjectName = n;                              \
    (p)->SecurityDescriptor = s;                      \
    (p)->SecurityQualityOfService = NULL;             \
    }

// Physical address

typedef LARGE_INTEGER PHYSICAL_ADDRESS,
        *PPHYSICAL_ADDRESS;

// Section Information Structures

typedef enum _SECTION_INHERIT
    {
    ViewShare = 1,
    ViewUnmap = 2
    }
    SECTION_INHERIT;

// Section Access Rights.

#ifndef SECTION_QUERY
#define SECTION_QUERY       0x0001
#define SECTION_MAP_WRITE   0x0002
#define SECTION_MAP_READ    0x0004
#define SECTION_MAP_EXECUTE 0x0008
#define SECTION_EXTEND_SIZE 0x0010

#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | \
                            SECTION_MAP_WRITE   | \
                            SECTION_MAP_READ    | \
                            SECTION_MAP_EXECUTE | \
                            SECTION_EXTEND_SIZE)
#endif

typedef struct _IO_STRUCT
    {
    DWORD Addr;
    DWORD Reserved1;
    PVOID pBuf;
    DWORD NumBytes;
    DWORD Reserved4;
    DWORD Reserved5;
    DWORD Reserved6;
    DWORD Reserved7;
    }
    IO_STRUCT;

#ifdef LIBSMBIOS_WIN_USE_WMI

// Define the WMI SMBIOS Information Structure

typedef struct _WMISMBIOSINFO
    {
    u8  majorVersion;
    u8  minorVersion;
    u32 bufferSize;
    u8* buffer;
    }
WMISMBIOSINFO;

#endif

#pragma pack (push, 1)

typedef struct MEM_STRUCT
    {
    DWORD Addr;
    DWORD Reserved1;
    void* pBuf;
    DWORD NumBytes;
    }
    MEM_STRUCT;

#pragma pack (pop)

typedef struct _STRING
    {
    USHORT Length;
    USHORT MaximumLength;
    PCHAR  Buffer;
    }
    ANSI_STRING,
  *PANSI_STRING;

typedef struct _IO_STATUS_BLOCK
    {
    union
        {
        NTSTATUS Status;
        PVOID    Pointer;
        };

    ULONG_PTR Information;
    }
    IO_STATUS_BLOCK,
  *PIO_STATUS_BLOCK;

#define NtCurrentProcess() ((HANDLE) -1)

// For Debug Control

typedef enum _DEBUG_CONTROL_CODE
    {
    DebugGetTraceInformation   = 1,
    DebugSetInternalBreakpoint,
    DebugSetSpecialCall,
    DebugClearSpecialCalls,
    DebugQuerySpecialCalls,
    DebugDbgBreakPoint,
    DebugMaximum,
    DebugSysReadPhysicalMemory = 10,
    DebugSysReadIoSpace        = 14,
    DebugSysWriteIoSpace       = 15
    }
    DEBUG_CONTROL_CODE;

#define FILE_OPEN    0x00000001
#define FILE_CREATE  0x00000002

typedef VOID* PPVOID;
typedef void (*PPEBLOCKROUTINE) (PVOID PebLock);

typedef struct _PEB_FREE_BLOCK
    {
    struct _PEB_FREE_BLOCK* Next;
    ULONG Size;
    }
    PEB_FREE_BLOCK,
  *PPEB_FREE_BLOCK;

typedef struct _RTL_DRIVE_LETTER_CURDIR
    {
    USHORT Flags;
    USHORT Length;
    ULONG TimeStamp;
    UNICODE_STRING DosPath;
    }
    RTL_DRIVE_LETTER_CURDIR,
  *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _LDR_MODULE
    {
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    PVOID BaseAddress;
    PVOID EntryPoint;
    ULONG SizeOfImage;
    UNICODE_STRING FullDllName;
    UNICODE_STRING BaseDllName;
    ULONG Flags;
    SHORT LoadCount;
    SHORT TlsIndex;
    LIST_ENTRY HashTableEntry;
    ULONG TimeDateStamp;
    }
    LDR_MODULE,
  *PLDR_MODULE;

typedef struct _PEB_LDR_DATA
    {
    ULONG Length;
    BOOLEAN Initialized;
    PVOID SsHandle;
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    } PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _RTL_USER_PROCESS_PARAMETERS
    {
    ULONG MaximumLength;
    ULONG Length;
    ULONG Flags;
    ULONG DebugFlags;
    PVOID ConsoleHandle;
    ULONG ConsoleFlags;
    HANDLE StdInputHandle;
    HANDLE StdOutputHandle;
    HANDLE StdErrorHandle;
    UNICODE_STRING CurrentDirectoryPath;
    HANDLE CurrentDirectoryHandle;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    PVOID Environment;
    ULONG StartingPositionLeft;
    ULONG StartingPositionTop;
    ULONG Width;
    ULONG Height;
    ULONG CharWidth;
    ULONG CharHeight;
    ULONG ConsoleTextAttributes;
    ULONG WindowFlags;
    ULONG ShowWindowFlags;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING DesktopName;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeData;
    RTL_DRIVE_LETTER_CURDIR DLCurrentDirectory[0x20];
    }
    RTL_USER_PROCESS_PARAMETERS,
  *PRTL_USER_PROCESS_PARAMETERS;

typedef struct _PEB
    {
    BOOLEAN InheritedAddressSpace;
    BOOLEAN ReadImageFileExecOptions;
    BOOLEAN BeingDebugged;
    BOOLEAN Spare;
    HANDLE Mutant;
    PVOID ImageBaseAddress;
    PPEB_LDR_DATA LoaderData;
    PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    PVOID SubSystemData;
    PVOID ProcessHeap;
    PVOID FastPebLock;
    PPEBLOCKROUTINE FastPebLockRoutine;
    PPEBLOCKROUTINE FastPebUnlockRoutine;
    ULONG EnvironmentUpdateCount;
    PPVOID KernelCallbackTable;
    PVOID EventLogSection;
    PVOID EventLog;
    PPEB_FREE_BLOCK FreeList;
    ULONG TlsExpansionCounter;
    PVOID TlsBitmap;
    ULONG TlsBitmapBits[0x2];
    PVOID ReadOnlySharedMemoryBase;
    PVOID ReadOnlySharedMemoryHeap;
    PPVOID ReadOnlyStaticServerData;
    PVOID AnsiCodePageData;
    PVOID OemCodePageData;
    PVOID UnicodeCaseTableData;
    ULONG NumberOfProcessors;
    ULONG NtGlobalFlag;
    BYTE Spare2[0x4];
    LARGE_INTEGER CriticalSectionTimeout;
    ULONG HeapSegmentReserve;
    ULONG HeapSegmentCommit;
    ULONG HeapDeCommitTotalFreeThreshold;
    ULONG HeapDeCommitFreeBlockThreshold;
    ULONG NumberOfHeaps;
    ULONG MaximumNumberOfHeaps;
    PPVOID* ProcessHeaps;
    PVOID GdiSharedHandleTable;
    PVOID ProcessStarterHelper;
    PVOID GdiDCAttributeList;
    PVOID LoaderLock;
    ULONG OSMajorVersion;
    ULONG OSMinorVersion;
    ULONG OSBuildNumber;
    ULONG OSPlatformId;
    ULONG ImageSubSystem;
    ULONG ImageSubSystemMajorVersion;
    ULONG ImageSubSystemMinorVersion;
    ULONG GdiHandleBuffer[0x22];
    ULONG PostProcessInitRoutine;
    ULONG TlsExpansionBitmap;
    BYTE TlsExpansionBitmapBits[0x80];
    ULONG SessionId;
    }
    PEB,
  *PPEB;

typedef struct _CLIENT_ID
    {
    PVOID UniqueProcess;
    PVOID UniqueThread;
    }
    CLIENT_ID,
  *PCLIENT_ID;

typedef struct _TEB
    {
    NT_TIB Tib;
    PVOID EnvironmentPointer;
    CLIENT_ID Cid;
    PVOID ActiveRpcInfo;
    PVOID ThreadLocalStoragePointer;
    PPEB Peb;
    ULONG LastErrorValue;
    ULONG CountOfOwnedCriticalSections;
    PVOID CsrClientThread;
    PVOID Win32ThreadInfo;
    ULONG Win32ClientInfo[0x1F];
    PVOID WOW32Reserved;
    ULONG CurrentLocale;
    ULONG FpSoftwareStatusRegister;
    PVOID SystemReserved1[0x36];
    PVOID Spare1;
    ULONG ExceptionCode;
    ULONG SpareBytes1[0x28];
    PVOID SystemReserved2[0xA];
    ULONG GdiRgn;
    ULONG GdiPen;
    ULONG GdiBrush;
    CLIENT_ID RealClientId;
    PVOID GdiCachedProcessHandle;
    ULONG GdiClientPID;
    ULONG GdiClientTID;
    PVOID GdiThreadLocaleInfo;
    PVOID UserReserved[5];
    PVOID GlDispatchTable[0x118];
    ULONG GlReserved1[0x1A];
    PVOID GlReserved2;
    PVOID GlSectionInfo;
    PVOID GlSection;
    PVOID GlTable;
    PVOID GlCurrentRC;
    PVOID GlContext;
    NTSTATUS LastStatusValue;
    UNICODE_STRING StaticUnicodeString;
    WCHAR StaticUnicodeBuffer[0x105];
    PVOID DeallocationStack;
    PVOID TlsSlots[0x40];
    LIST_ENTRY TlsLinks;
    PVOID Vdm;
    PVOID ReservedForNtRpc;
    PVOID DbgSsReserved[0x2];
    ULONG HardErrorDisabled;
    PVOID Instrumentation[0x10];
    PVOID WinSockData;
    ULONG GdiBatchCount;
    ULONG Spare2;
    ULONG Spare3;
    ULONG Spare4;
    PVOID ReservedForOle;
    ULONG WaitingOnLoaderLock;
    PVOID StackCommit;
    PVOID StackCommitMax;
    PVOID StackReserved;
    }
    TEB,
  *PTEB;

#define NtCurrentTeb()         \
    ({                         \
    TEB* ret;                  \
    __asm__ ("movl %%fs:0x18, %0\n" : "=r" (ret) : ); \
    ret;                       \
    })

#endif

