#pragma once

#include "../UEGameProfile.hpp"
using namespace UEMemory;

class PESProfile : public IGameProfile
{
public:
    PESProfile() = default;

    bool ArchSupprted() const override
    {
        auto e_machine = GetUnrealELF().header().e_machine;
        return e_machine == EM_AARCH64;
    }

    std::string GetAppName() const override
    {
        return "eFootball (PES)";
    }

    std::vector<std::string> GetAppIDs() const override
    {
        return {"jp.konami.pesam"};
    }

    bool isUsingCasePreservingName() const override
    {
        return false;
    }

    bool IsUsingFNamePool() const override
    {
        return true;
    }

    bool isUsingOutlineNumberName() const override
    {
        return false;
    }

    uintptr_t GetGUObjectArrayPtr() const override
    {
        return 0x8f40268;
    }

    uintptr_t GetNamesPtr() const override
    {        
        return 0xb7b79c;
    }

    UE_Offsets *GetOffsets() const override
    {
        static UE_Offsets offsets = UE_DefaultOffsets::UE4_25_27(isUsingCasePreservingName());
        return &offsets;
    }
};
