#pragma once
typedef int vm_prot_t;

#define VM_PROT_NONE    ((vm_prot_t) 0x00)

#define VM_PROT_READ    ((vm_prot_t) 0x01)
#define VM_PROT_WRITE   ((vm_prot_t) 0x02)
#define VM_PROT_EXECUTE ((vm_prot_t) 0x04)
