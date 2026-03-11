// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheSliders : ModuleRules
{
	public TheSliders(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
        { 
	        "Core", 
            "CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"Paper2D",
			"GameplayAbilities",
			"GameplayTasks",
			"GameplayTags",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
    }
}
