#pragma once

#define NON_COPYABLE_WITH_NON_DESTRUCTOR(NonCopyableClass) \
private: \
	NonCopyableClass() = default; \
	NonCopyableClass(const NonCopyableClass& other) = delete; \
	NonCopyableClass& operator=(const NonCopyableClass& other) = delete; \
public: \
	static NonCopyableClass& GetInst() \
	{ \
		static NonCopyableClass instance; \
		return instance; \
	} \
private:

#define NON_COPYABLE(NonCopyableClass) \
	NON_COPYABLE_WITH_NON_DESTRUCTOR(NonCopyableClass) \
private: \
	~NonCopyableClass() = default;

#define CHECK_RETVAL_WITH_BREAK(input) \
if (FAILED(input) == true) \
{ \
	break; \
}