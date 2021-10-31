#pragma once

#include "Untitled_DeckRPG/DeckRPG.h"

#include "DeckDataAsset.generated.h"

UCLASS()
class UNTITLED_DECKRPG_API UDeckDataAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
	
    // ======================================
    // ===== CONSTRUCTORS_/_DESTRUCTORS =====
    // ======================================
    private:
    protected:
    public:
    // ======================
    // ===== PROPERTIES =====
    // ======================
    private:
    protected:
	public:
	/** The type of item this is, defined in native parent class */
	UPROPERTY(BlueprintReadOnly, Category=DataAsset)
	FPrimaryAssetType ItemType;
	
    // =============================
    // ===== GETTERS_/_SETTERS =====
    // =============================
    private:
    protected:
    public:
    /** returns a string representation of FPrimaryAssetId */
    FString GetAssetIdAsString() const { return GetPrimaryAssetId().ToString(); }
	
    /** Override of GetPrimaryAssetId, returns pair of ItemType : GetFName() */
    virtual FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId(ItemType, GetFName()); }
	
    // ===================
    // ===== METHODS =====
    // ===================
    private:
    protected:
    public:
};
