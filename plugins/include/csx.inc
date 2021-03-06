// vim: set ts=4 sw=4 tw=99 noet:
//
// AMX Mod X, based on AMX Mod by Aleksander Naszko ("OLO").
// Copyright (C) The AMX Mod X Development Team.
//
// This software is licensed under the GNU General Public License, version 3 or higher.
// Additional exceptions apply. For full license details, see LICENSE.txt or visit:
//     https://alliedmods.net/amxmodx-license

//
// CSX Functions
//

#if defined _csx_included
  #endinput
#endif
#define _csx_included

#include <csstats>

#if AMXX_VERSION_NUM >= 175
 #pragma reqclass xstats
 #if !defined AMXMODX_NOAUTOLOAD
  #pragma defclasslib xstats csx
 #endif
#else
 #pragma library csx
#endif

/*
 * Forwards
 */

/* Function is called after player to player attacks ,
* if players were damaged by teammate TA is set to 1 */
forward client_damage(attacker,victim,damage,wpnindex,hitplace,TA);

/* Function is called after player death ,
* if player was killed by teammate TK is set to 1 */
forward client_death(killer,victim,wpnindex,hitplace,TK);

forward grenade_throw( index,greindex,wId );

forward bomb_planting(planter);
forward bomb_planted(planter);
forward bomb_explode(planter,defuser);
forward bomb_defusing(defuser);
forward bomb_defused(defuser);

/************* Shared Natives Start ********************************/

/* Custom Weapon Support */
/* function will return index of new weapon */
native custom_weapon_add( const wpnname[],melee = 0,const logname[]="" ); 
/* Function will pass damage done by this custom weapon to stats module and other plugins */
native custom_weapon_dmg( weapon, att, vic, damage, hitplace=0 ); 
/* Function will pass info about custom weapon shot to stats module */
native custom_weapon_shot( weapon,index ); // weapon id , player id

/* function will return 1 if true */
native xmod_is_melee_wpn(wpnindex);

/* Returns weapon name. */
native xmod_get_wpnname(wpnindex,name[],len);

/* Returns weapon logname. */
native xmod_get_wpnlogname(wpnindex,name[],len);

/* Returns weapons array size */
native xmod_get_maxweapons();

/* Returns stats array size */
native xmod_get_stats_size();

/************* Shared Natives End ********************************/

enum MapObjective
{
	MapObjective_Bomb	 = (1<<0),
	MapObjective_Hostage = (1<<1),
	MapObjective_Vip	 = (1<<2),
	MapObjective_Escape  = (1<<3),
};

/**
 * Gets current map objectives.
 *
 * @return 		Returns a bits sum if objectives are found, otherwise 0. 
 * 				See MapObjective_* constants.
 */
native MapObjective:get_map_objectives();
