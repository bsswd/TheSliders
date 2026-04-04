// The Sliders Game. Made by Alex Sinkin (C)


#include "GameplayTags/TSTags.h"


namespace TSTags
{
	namespace Abilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "TSTags.Abilities.ActivateOnGiven", "Tag for activate ability on given")
		
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeAttack, "TSTags.Abilities.Player.MeleeAttack", "Tag for player melee attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(RangeAttack, "TSTags.Abilities.Player.RangeAttack", "Tag for player range attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(DocSelect, "TSTags.Abilities.Player.DocSelect", "Tag for player select Doc character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(BaldSelect, "TSTags.Abilities.Player.BaldSelect", "Tag for player select Bald character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(LawSelect, "TSTags.Abilities.Player.LawSelect", "Tag for player select Law character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(SazzSelect, "TSTags.Abilities.Player.SazzSelect", "Tag for player select Sazz character")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(JokaSelect, "TSTags.Abilities.Player.JokaSelect", "Tag for player select Joka character")
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeAttack, "TSTags.Abilities.Enemy.MeleeAttack", "Tag for enemy melee attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(RangeAttack, "TSTags.Abilities.Enemy.RangeAttack", "Tag for enemy range attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Jump, "TSTags.Abilities.Enemy.Jump", "Tag for enemy jump")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "TSTags.Abilities.Enemy.HitReact", "Tag for enemy hit react")
		}
	}
	
	namespace  Events
	{
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeAttack, "TSTags.Events.Player.MeleeAttack", "Tag for player melee attack event");
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "TSTags.Events.Enemy.HitReact", "Tag for player enemy hit react event");
		}
	}
}