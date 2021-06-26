#pragma once


#include "log.h"

#include "m_pd.h"
#include "vocaldetector.h"


t_symbol *s_tabtype_sig;
t_symbol *s_tabtype_pb;


typedef struct _voxel_tilde {
    t_object x_obj;
    t_sample f;

    vocaldetector *vd;

    float frequency;
    t_outlet *out_frequency;
} voxel_tilde;


void *voxel_tilde_new(void);

void voxel_tilde_free(voxel_tilde *x);

void voxel_tilde_setup(void);
