/*
 * Copyright 2012-15 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DAL_DC_COMMON_H__
#define __DAL_DC_COMMON_H__

#include "core_types.h"

bool is_rgb_cspace(enum dc_color_space output_color_space);

<<<<<<< HEAD
bool is_child_pipe_tree_visible(struct pipe_ctx *pipe_ctx);

bool is_parent_pipe_tree_visible(struct pipe_ctx *pipe_ctx);
=======
bool is_lower_pipe_tree_visible(struct pipe_ctx *pipe_ctx);

bool is_upper_pipe_tree_visible(struct pipe_ctx *pipe_ctx);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

bool is_pipe_tree_visible(struct pipe_ctx *pipe_ctx);

void build_prescale_params(struct  dc_bias_and_scale *bias_and_scale,
		const struct dc_plane_state *plane_state);

#endif
