typedef struct Region0_Description{
	unsigned long	lbaddr;		//Lower Address Boundary
	unsigned long	hbaddr;		//Higher Address Boundary
	char*			description;//Short description for the register
}REG0DESCR;

// The Reg's Database
static REG0DESCR REG0_Entry[] = {
	{0x80000000,0x80000003,"Reserved for system use"},
	{0x80000004,0x8000000F,"Reserved for system use"},
	{0x80000010,0x80000013,"Reserved for system use"},
	{0x80000014,0x8000003F,"Reserved for system use"},
	{0x80000040,0x8000004F,"High priority Breakpoint trap handler"},
	{0x80000050,0x8000005F,"High priority Breakpoint trapped process"},
	{0x80000060,0x8000006F,"High priority Error trap handler"},
	{0x80000070,0x8000007F,"High priority Error trapped process"},
	{0x80000080,0x8000008F,"High priority SystemOperations trap handler"},
	{0x80000090,0x8000009F,"High priority SystemOperations trapped process"},
	{0x800000A0,0x800000AF,"High priority Scheduler trap handler"},
	{0x800000B0,0x800000BF,"High priority Scheduler trapped process"},
	{0x800000C0,0x800000CF,"Low priority Breakpoint trap handler"},
	{0x800000D0,0x800000DF,"Low priority Breakpoint trapped process"},
	{0x800000E0,0x800000EF,"Low priority Error trap handler"},
	{0x800000F0,0x800000FF,"Low priority Error trapped process"},
	{0x80000100,0x8000010F,"Low priority SystemOperations trap handler"},
	{0x80000110,0x8000011F,"Low priority SystemOperations trapped process"},
	{0x80000120,0x8000012F,"Low priority Scheduler trap handler"},
	{0x80000130,0x8000013F,"Low priority Scheduler trapped process"},
	{0x80000140,0x80000FFF,"Internal SRAM: < 4 Kbytes user code, data and stack"},
	//{0x80001000,0x800017FF,"Internal SRAM if data cache is not enabled.User-code, data and stack"},
	{0x00,0x00,"??"}
};