#pragma once

#define NON_COPYABLE(NonCopyableClass) \
private: \
	NonCopyableClass() = default; \
	~NonCopyableClass() = default; \
	NonCopyableClass(const NonCopyableClass& other) = delete; \
	NonCopyableClass& operator=(const NonCopyableClass& other) = delete; \
public: \
	static NonCopyableClass& GetInst() \
	{ \
		static NonCopyableClass instance; \
		return instance; \
	}