// The Sliders Game. Made by Alex Sinkin (C)


#include "GameplayTags/TSTags.h"


namespace TSTags
{
	namespace TSAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "TSTags.TSAbilities.ActivateOnGiven", "Tag for activate ability on given")
		
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeAttack, "TSTags.TSAbilities.Player.MeleeAttack", "Tag for player melee attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(RangeAttack, "TSTags.TSAbilities.Player.RangeAttack", "Tag for player range attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(DocSelect, "TSTags.TSAbilities.Player.DocSelect", "Tag for player select Doc character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(BaldSelect, "TSTags.TSAbilities.Player.BaldSelect", "Tag for player select Bald character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(LawSelect, "TSTags.TSAbilities.Player.LawSelect", "Tag for player select Law character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(SazzSelect, "TSTags.TSAbilities.Player.SazzSelect", "Tag for player select Sazz character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(JokaSelect, "TSTags.TSAbilities.Player.JokaSelect", "Tag for player select Joka character")
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeAttack, "TSTags.TSAbilities.Enemy.MeleeAttack", "Tag for enemy melee attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(RangeAttack, "TSTags.TSAbilities.Enemy.RangeAttack", "Tag for enemy range attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Jump, "TSTags.TSAbilities.Enemy.Jump", "Tag for enemy jump")
		}
		
	}
}