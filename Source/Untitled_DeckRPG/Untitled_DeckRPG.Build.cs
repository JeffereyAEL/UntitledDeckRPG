// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Untitled_DeckRPG : ModuleRules
{
	public Untitled_DeckRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivatePCHHeaderFile = "DeckRPG.h";
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", 
			"Slate", "SlateCore", "Paper2D" });
		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", 
			"GameplayTasks"});
	}
}
