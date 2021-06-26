#include "voxel~.h"
#include <string.h>
#include <unistd.h>


static t_class *voxel_tilde_class;


void *voxel_tilde_new(void) {
    voxel_tilde *x = (voxel_tilde *) pd_new(voxel_tilde_class);
    if (!x) return NULL;

    x->vd = vd_new();
    if (!x->vd) return NULL;

    x->frequency = 0.0f;
    x->out_frequency = outlet_new(&x->x_obj, &s_float);

    return (void *) x;
}

void voxel_tilde_free(voxel_tilde *x) {
    vd_free(x->vd);
}

static t_int *voxel_tilde_perform(t_int *w) {
    w++;

    voxel_tilde *x = (voxel_tilde *) *w++;
    t_sample *in = (t_sample *) *w++;
    int n = (int) *w++;

    // invoke the vocal detector
    vd_perform(x->vd, in, n);

    // output the current frequency
    float new_frequency;
    if (x->vd->period < 0.0f) new_frequency = 0.0f;
    else new_frequency = 44100.0f / x->vd->period;

    if (new_frequency != x->frequency) {
        x->frequency = new_frequency;
        outlet_float(x->out_frequency, new_frequency);
    }

    return w;
}

static void voxel_tilde_dsp(voxel_tilde *x, t_signal **sp) {
    dsp_add(voxel_tilde_perform, 3, x, sp[0]->s_vec, sp[0]->s_n);
}

void voxel_tilde_setup(void) {
    voxel_tilde_class = class_new(gensym("voxel~"),
        (t_newmethod) voxel_tilde_new,
        (t_method) voxel_tilde_free,
        sizeof(voxel_tilde),
        CLASS_DEFAULT,
        A_NULL);

    class_addmethod(voxel_tilde_class,
        (t_method) voxel_tilde_dsp,
        gensym("dsp"),
        A_CANT,
        A_NULL);

    CLASS_MAINSIGNALIN(voxel_tilde_class, voxel_tilde, f);
}
