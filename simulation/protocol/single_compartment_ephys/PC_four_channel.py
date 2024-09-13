
#Amelia Burroughs

import numpy as np
from scipy.integrate import ode
import matplotlib.pyplot as plt
from Units import *
from Parameters_4 import *
import matplotlib.lines as l
import time
import datetime

#print "cf_a[0]/uA: "+str(cf_a[0]/uA)


class Somatic_voltage:

    def __init__(self,c,g_rna,g_k,g_sk,g_ca,g_leak,e_na,e_k,e_ca,e_leak,i_e,v_initial):

        self.c=c
        self.g_rna=g_rna
        self.g_k=g_k
        self.g_leak=g_leak
        self.e_na=e_na
        self.e_k=e_k
        self.e_leak=e_leak
        self.i_e=i_e
        self.g_sk=g_sk
        self.g_ca=g_ca
        self.e_ca=e_ca

        self.v_initial=v_initial

    def derivative(self,k_n,rna_o,sk_w,ca_m,v_soma,t):

        i_rna=-self.g_rna*rna_o*(v_soma-self.e_na)
        i_k =-self.g_k *pow(k_n,4)*(v_soma-self.e_k)
        i_leak=-self.g_leak*(v_soma-self.e_leak)
        i_sk=-self.g_sk*sk_w*(v_soma-self.e_k)
        i_ca = -self.g_ca*ca_m*(v_soma-self.e_ca)


#        i_rna_trace.append(i_rna)
#        i_k_trace.append(i_k)
#        i_leak_trace.append(i_leak)
        
        soma_v = (self.i_e(t)+i_rna+i_k+i_sk+i_ca+i_leak)/self.c
        # we need all current
        return soma_v, i_ca,self.i_e(t)

class All_derivatives:
    
    def __init__(self,somatic_voltage,rna_states,rate_k,rate_sk,rate_ca,rate_ca_concentration):

        self.somatic_voltage=somatic_voltage
        self.rna_states=rna_states
        self.rate_k=rate_k
        self.rate_sk=rate_sk
        self.rate_ca=rate_ca
        self.rate_ca_concentration=rate_ca_concentration


    def __call__(self,t,y):

        v_soma=y[0]
        k_n   =y[1]
        rna_y =y[2:15]
        rna_o =y[7]
        sk_w=y[15]
        ca_m=y[16]
        ca_concentration=y[17]

        v_soma_dot,i_ca,i_electrode=self.somatic_voltage.derivative(k_n,rna_o,sk_w,ca_m,v_soma,t)
        
        k_n_dot=self.rate_k.alpha(v_soma)*(1-k_n)-self.rate_k.beta(v_soma)*k_n
 
        rna_y_dot=self.rna_states.all_dots(rna_y,v_soma)

        sk_w_dot = (self.rate_sk.inf_w(ca_concentration) - sk_w) / self.rate_sk.tau_w(ca_concentration)
        ca_m_dot = self.rate_ca.alpha_ca(v_soma)*(1-ca_m)-self.rate_ca.beta_ca(v_soma)*ca_m

        ca_concentration_dot = (i_ca*gamma_ca - self.rate_ca_concentration.calcium_tau*(ca_concentration-baseline_calcium_concentration)) + (i_electrode*gamma_ca*scale_factor)

        return [v_soma_dot,k_n_dot]+rna_y_dot+[sk_w_dot, ca_m_dot, ca_concentration_dot]

def normalize(y):

    total=0

    for i in range(2,15):
        total+=y[i]

    for i in range(2,15):
        y[i]/=total

    return y

rate_k=Rate_k()
rate_sk = Rate_sk1()
rate_ca = Rate_ca()
rate_ca_concentration = Rate_ca_concentration(calcium_decay_constant)


rna_states=Rna_states(
    full_rna_alpha,
    full_rna_beta,
    full_rna_gamma,
    full_rna_delta,
    full_rna_epsilon,
    full_rna_xi,
    full_rna_d,
    full_rna_u,
    full_rna_n,
    full_rna_f,
    v_initial
    )





