/* Copyright 2020 Paul James
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define LAYOUT_ortho_5x12( \
	k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
	k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b \
) \
{ \
	{ k00, k01, k02, k03, k04, k0b, k0a, k09, k08, k07 }, \
	{ k10, k11, k12, k13, k05, k1b, k1a, k19, k18, k06 }, \
	{ k20, k21, k22, k14, k15, k2b, k2a, k29, k17, k16 }, \
	{ k30, k31, k23, k24, k25, k3b, k3a, k28, k27, k26 }, \
	{ k40, k32, k33, k34, k35, k4b, k39, k38, k37, k36 }, \
	{ k41, k42, k43, k44, k45, k4a, k49, k48, k47, k46 } \
}

#define LED1 C5
#define LED2 C4

void led_set_state(bool led1, bool led2);
