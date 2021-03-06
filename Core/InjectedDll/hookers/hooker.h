#ifndef HOOKER_H
#define HOOKER_H

#include <Windows.h>
#include <list>
#include "commands/command.h"
#include "commands/command_factory.h"

using std::list;

/**
 * class that is responsible for hooking functions.
 *
 * @note: we take advantage of the fact that league supports hotpatching (idk why)
 */
class Hooker{
public:
	/**
	 * construct a new Hooker
	 * @param callback -	the function to be called when the hook pops
	 *						should jmp back to hook location
	 * @param patch_addr -	the location to install the patch at
	 */
	Hooker(DWORD callback, DWORD patch_addr);

	~Hooker();

	/**
	 * hook main_loop function
	 * @throws runtime_error if failed
	 */
	void install_hook();

	/**
	 * returns the address where the hook is/will be installed
	 */
	DWORD get_hook_addr();

private:
	/**
	 * install a hotpatch at a given address
	 * @throws runtime_error if failed
	 */
	void hotpatch(DWORD address, DWORD callback);

	/**
	 * Change the protection of address - address + size to protection.
	 * returns the old protection.
	 * @throws runtime_error if fails
	 */
	DWORD change_protection(DWORD address, DWORD protection, size_t size);

	/**
	 * get relative address. used to get the address to jmp for a jmp instruction
	 */
	DWORD get_relative_address(DWORD from, DWORD to, size_t instruction_size=5);

	char m_original_bytes[2];
	bool m_is_hooked;
	DWORD m_hook_addr;
	DWORD m_callback;
};

#endif // ndef HOOKER_H