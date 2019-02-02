/**
  Copyright © 2015 Odzhan. All Rights Reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  3. The name of the author may not be used to endorse or promote products
  derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

static const uint32_t DES_sbox[8][64]={
{
/* nibble 0 */
0x02080800L, 0x00080000L, 0x02000002L, 0x02080802L,
0x02000000L, 0x00080802L, 0x00080002L, 0x02000002L,
0x00080802L, 0x02080800L, 0x02080000L, 0x00000802L,
0x02000802L, 0x02000000L, 0x00000000L, 0x00080002L,
0x00080000L, 0x00000002L, 0x02000800L, 0x00080800L,
0x02080802L, 0x02080000L, 0x00000802L, 0x02000800L,
0x00000002L, 0x00000800L, 0x00080800L, 0x02080002L,
0x00000800L, 0x02000802L, 0x02080002L, 0x00000000L,
0x00000000L, 0x02080802L, 0x02000800L, 0x00080002L,
0x02080800L, 0x00080000L, 0x00000802L, 0x02000800L,
0x02080002L, 0x00000800L, 0x00080800L, 0x02000002L,
0x00080802L, 0x00000002L, 0x02000002L, 0x02080000L,
0x02080802L, 0x00080800L, 0x02080000L, 0x02000802L,
0x02000000L, 0x00000802L, 0x00080002L, 0x00000000L,
0x00080000L, 0x02000000L, 0x02000802L, 0x02080800L,
0x00000002L, 0x02080002L, 0x00000800L, 0x00080802L,
},{
/* nibble 1 */
0x40108010L, 0x00000000L, 0x00108000L, 0x40100000L,
0x40000010L, 0x00008010L, 0x40008000L, 0x00108000L,
0x00008000L, 0x40100010L, 0x00000010L, 0x40008000L,
0x00100010L, 0x40108000L, 0x40100000L, 0x00000010L,
0x00100000L, 0x40008010L, 0x40100010L, 0x00008000L,
0x00108010L, 0x40000000L, 0x00000000L, 0x00100010L,
0x40008010L, 0x00108010L, 0x40108000L, 0x40000010L,
0x40000000L, 0x00100000L, 0x00008010L, 0x40108010L,
0x00100010L, 0x40108000L, 0x40008000L, 0x00108010L,
0x40108010L, 0x00100010L, 0x40000010L, 0x00000000L,
0x40000000L, 0x00008010L, 0x00100000L, 0x40100010L,
0x00008000L, 0x40000000L, 0x00108010L, 0x40008010L,
0x40108000L, 0x00008000L, 0x00000000L, 0x40000010L,
0x00000010L, 0x40108010L, 0x00108000L, 0x40100000L,
0x40100010L, 0x00100000L, 0x00008010L, 0x40008000L,
0x40008010L, 0x00000010L, 0x40100000L, 0x00108000L,
},{
/* nibble 2 */
0x04000001L, 0x04040100L, 0x00000100L, 0x04000101L,
0x00040001L, 0x04000000L, 0x04000101L, 0x00040100L,
0x04000100L, 0x00040000L, 0x04040000L, 0x00000001L,
0x04040101L, 0x00000101L, 0x00000001L, 0x04040001L,
0x00000000L, 0x00040001L, 0x04040100L, 0x00000100L,
0x00000101L, 0x04040101L, 0x00040000L, 0x04000001L,
0x04040001L, 0x04000100L, 0x00040101L, 0x04040000L,
0x00040100L, 0x00000000L, 0x04000000L, 0x00040101L,
0x04040100L, 0x00000100L, 0x00000001L, 0x00040000L,
0x00000101L, 0x00040001L, 0x04040000L, 0x04000101L,
0x00000000L, 0x04040100L, 0x00040100L, 0x04040001L,
0x00040001L, 0x04000000L, 0x04040101L, 0x00000001L,
0x00040101L, 0x04000001L, 0x04000000L, 0x04040101L,
0x00040000L, 0x04000100L, 0x04000101L, 0x00040100L,
0x04000100L, 0x00000000L, 0x04040001L, 0x00000101L,
0x04000001L, 0x00040101L, 0x00000100L, 0x04040000L,
},{
/* nibble 3 */
0x00401008L, 0x10001000L, 0x00000008L, 0x10401008L,
0x00000000L, 0x10400000L, 0x10001008L, 0x00400008L,
0x10401000L, 0x10000008L, 0x10000000L, 0x00001008L,
0x10000008L, 0x00401008L, 0x00400000L, 0x10000000L,
0x10400008L, 0x00401000L, 0x00001000L, 0x00000008L,
0x00401000L, 0x10001008L, 0x10400000L, 0x00001000L,
0x00001008L, 0x00000000L, 0x00400008L, 0x10401000L,
0x10001000L, 0x10400008L, 0x10401008L, 0x00400000L,
0x10400008L, 0x00001008L, 0x00400000L, 0x10000008L,
0x00401000L, 0x10001000L, 0x00000008L, 0x10400000L,
0x10001008L, 0x00000000L, 0x00001000L, 0x00400008L,
0x00000000L, 0x10400008L, 0x10401000L, 0x00001000L,
0x10000000L, 0x10401008L, 0x00401008L, 0x00400000L,
0x10401008L, 0x00000008L, 0x10001000L, 0x00401008L,
0x00400008L, 0x00401000L, 0x10400000L, 0x10001008L,
0x00001008L, 0x10000000L, 0x10000008L, 0x10401000L,
},{
/* nibble 4 */
0x08000000L, 0x00010000L, 0x00000400L, 0x08010420L,
0x08010020L, 0x08000400L, 0x00010420L, 0x08010000L,
0x00010000L, 0x00000020L, 0x08000020L, 0x00010400L,
0x08000420L, 0x08010020L, 0x08010400L, 0x00000000L,
0x00010400L, 0x08000000L, 0x00010020L, 0x00000420L,
0x08000400L, 0x00010420L, 0x00000000L, 0x08000020L,
0x00000020L, 0x08000420L, 0x08010420L, 0x00010020L,
0x08010000L, 0x00000400L, 0x00000420L, 0x08010400L,
0x08010400L, 0x08000420L, 0x00010020L, 0x08010000L,
0x00010000L, 0x00000020L, 0x08000020L, 0x08000400L,
0x08000000L, 0x00010400L, 0x08010420L, 0x00000000L,
0x00010420L, 0x08000000L, 0x00000400L, 0x00010020L,
0x08000420L, 0x00000400L, 0x00000000L, 0x08010420L,
0x08010020L, 0x08010400L, 0x00000420L, 0x00010000L,
0x00010400L, 0x08010020L, 0x08000400L, 0x00000420L,
0x00000020L, 0x00010420L, 0x08010000L, 0x08000020L,
},{
/* nibble 5 */
0x80000040L, 0x00200040L, 0x00000000L, 0x80202000L,
0x00200040L, 0x00002000L, 0x80002040L, 0x00200000L,
0x00002040L, 0x80202040L, 0x00202000L, 0x80000000L,
0x80002000L, 0x80000040L, 0x80200000L, 0x00202040L,
0x00200000L, 0x80002040L, 0x80200040L, 0x00000000L,
0x00002000L, 0x00000040L, 0x80202000L, 0x80200040L,
0x80202040L, 0x80200000L, 0x80000000L, 0x00002040L,
0x00000040L, 0x00202000L, 0x00202040L, 0x80002000L,
0x00002040L, 0x80000000L, 0x80002000L, 0x00202040L,
0x80202000L, 0x00200040L, 0x00000000L, 0x80002000L,
0x80000000L, 0x00002000L, 0x80200040L, 0x00200000L,
0x00200040L, 0x80202040L, 0x00202000L, 0x00000040L,
0x80202040L, 0x00202000L, 0x00200000L, 0x80002040L,
0x80000040L, 0x80200000L, 0x00202040L, 0x00000000L,
0x00002000L, 0x80000040L, 0x80002040L, 0x80202000L,
0x80200000L, 0x00002040L, 0x00000040L, 0x80200040L,
},{
/* nibble 6 */
0x00004000L, 0x00000200L, 0x01000200L, 0x01000004L,
0x01004204L, 0x00004004L, 0x00004200L, 0x00000000L,
0x01000000L, 0x01000204L, 0x00000204L, 0x01004000L,
0x00000004L, 0x01004200L, 0x01004000L, 0x00000204L,
0x01000204L, 0x00004000L, 0x00004004L, 0x01004204L,
0x00000000L, 0x01000200L, 0x01000004L, 0x00004200L,
0x01004004L, 0x00004204L, 0x01004200L, 0x00000004L,
0x00004204L, 0x01004004L, 0x00000200L, 0x01000000L,
0x00004204L, 0x01004000L, 0x01004004L, 0x00000204L,
0x00004000L, 0x00000200L, 0x01000000L, 0x01004004L,
0x01000204L, 0x00004204L, 0x00004200L, 0x00000000L,
0x00000200L, 0x01000004L, 0x00000004L, 0x01000200L,
0x00000000L, 0x01000204L, 0x01000200L, 0x00004200L,
0x00000204L, 0x00004000L, 0x01004204L, 0x01000000L,
0x01004200L, 0x00000004L, 0x00004004L, 0x01004204L,
0x01000004L, 0x01004200L, 0x01004000L, 0x00004004L,
},{
/* nibble 7 */
0x20800080L, 0x20820000L, 0x00020080L, 0x00000000L,
0x20020000L, 0x00800080L, 0x20800000L, 0x20820080L,
0x00000080L, 0x20000000L, 0x00820000L, 0x00020080L,
0x00820080L, 0x20020080L, 0x20000080L, 0x20800000L,
0x00020000L, 0x00820080L, 0x00800080L, 0x20020000L,
0x20820080L, 0x20000080L, 0x00000000L, 0x00820000L,
0x20000000L, 0x00800000L, 0x20020080L, 0x20800080L,
0x00800000L, 0x00020000L, 0x20820000L, 0x00000080L,
0x00800000L, 0x00020000L, 0x20000080L, 0x20820080L,
0x00020080L, 0x20000000L, 0x00000000L, 0x00820000L,
0x20800080L, 0x20020080L, 0x20020000L, 0x00800080L,
0x20820000L, 0x00000080L, 0x00800080L, 0x20020000L,
0x20820080L, 0x00800000L, 0x20800000L, 0x20000080L,
0x00820000L, 0x00020080L, 0x20020080L, 0x20800000L,
0x00000080L, 0x20820000L, 0x00820080L, 0x00000000L,
0x20000000L, 0x20800080L, 0x00020000L, 0x00820080L,
}};

#define PERM_OP(a,b,t,n,m) ((t)=((((a)>>(n))^(b))&(m)),\
        (b)^=(t),\
        (a)^=((t)<<(n)))

#define IP(l,r) \
        { \
        register uint32_t tt; \
        PERM_OP(r,l,tt, 4,0x0f0f0f0fL); \
        PERM_OP(l,r,tt,16,0x0000ffffL); \
        PERM_OP(r,l,tt, 2,0x33333333L); \
        PERM_OP(l,r,tt, 8,0x00ff00ffL); \
        PERM_OP(r,l,tt, 1,0x55555555L); \
        }

#define LOAD_DATA_tmp(a,b,c,d,e,f) LOAD_DATA(a,b,c,d,e,f,g)
#define LOAD_DATA(R,S,u,t,E0,E1,tmp) \
        u=R^k[S  ]; \
        t=R^k[S+1]
#define ROTATE(a,n)(((a)>>(n))+((a)<<(32-(n))))

#define DES_F(LL,R,S) {\
        LOAD_DATA_tmp(R,S,u,t,E0,E1); \
        t=ROTATE(t,4); \
        LL^=DES_sbox[0][(u>> 2L)&0x3f]^ \
            DES_sbox[2][(u>>10L)&0x3f]^ \
            DES_sbox[4][(u>>18L)&0x3f]^ \
            DES_sbox[6][(u>>26L)&0x3f]^ \
            DES_sbox[1][(t>> 2L)&0x3f]^ \
            DES_sbox[3][(t>>10L)&0x3f]^ \
            DES_sbox[5][(t>>18L)&0x3f]^ \
            DES_sbox[7][(t>>26L)&0x3f]; }
            
// create DES subkeys using precomputed schedules
// using AVX2 is slightly faster than SSE2, but not by much.
#if defined(AVX2)
#include <immintrin.h>

#define DES_SET_KEY(idx) { \
    __m256i *s = (__m256i*)&ks_tbl[idx-1][c->pwd_idx[idx-1]]; \
    __m256i *p = (__m256i*)&ks[idx]; \
    __m256i *d = (__m256i*)&ks[idx-1]; \
    if (idx == 7) { \
        d[0] = s[0]; d[1] = s[1]; \
        d[2] = s[2]; d[3] = s[3]; \
    } else { \
        d[0] = _mm256_or_si256(s[0], p[0]); \
        d[1] = _mm256_or_si256(s[1], p[1]); \
        d[2] = _mm256_or_si256(s[2], p[2]); \
        d[3] = _mm256_or_si256(s[3], p[3]); \
    } \
}
#elif defined(SSE2)
#include <emmintrin.h>

#define DES_SET_KEY(idx) { \
    __m128i *s = (__m128i*)&ks_tbl[idx-1][c->pwd_idx[idx-1]]; \
    __m128i *p = (__m128i*)&ks[idx]; \
    __m128i *d = (__m128i*)&ks[idx-1]; \
    if (idx == 7) {\
        d[0] = s[0]; d[1] = s[1]; \
        d[2] = s[2]; d[3] = s[3]; \
        d[4] = s[4]; d[5] = s[5]; \
        d[6] = s[6]; d[7] = s[7]; \
    } else { \
        d[0] = _mm_or_si128(s[0], p[0]); \
        d[1] = _mm_or_si128(s[1], p[1]); \
        d[2] = _mm_or_si128(s[2], p[2]); \
        d[3] = _mm_or_si128(s[3], p[3]); \
        d[4] = _mm_or_si128(s[4], p[4]); \
        d[5] = _mm_or_si128(s[5], p[5]); \
        d[6] = _mm_or_si128(s[6], p[6]); \
        d[7] = _mm_or_si128(s[7], p[7]); \
    } \
}
#else
#define DES_SET_KEY(idx) { \
    uint64_t *p = (uint64_t*)&ks[idx]; \
    uint64_t *s = (uint64_t*)&ks_tbl[idx-1][c->pwd_idx[idx-1]]; \
    uint64_t *d = (uint64_t*)&ks[idx-1]; \
    \
    d[ 0]=s[ 0]; d[ 1]=s[ 1]; d[ 2]=s[ 2]; d[ 3]=s[ 3]; \
    d[ 4]=s[ 4]; d[ 5]=s[ 5]; d[ 6]=s[ 6]; d[ 7]=s[ 7]; \
    d[ 8]=s[ 8]; d[ 9]=s[ 9]; d[10]=s[10]; d[11]=s[11]; \
    d[12]=s[12]; d[13]=s[13]; d[14]=s[14]; d[15]=s[15]; \
    \
    if(idx < 7) { \
      d[ 0] |= p[ 0]; d[ 1] |= p[ 1]; \
      d[ 2] |= p[ 2]; d[ 3] |= p[ 3]; \
      d[ 4] |= p[ 4]; d[ 5] |= p[ 5]; \
      d[ 6] |= p[ 6]; d[ 7] |= p[ 7]; \
      d[ 8] |= p[ 8]; d[ 9] |= p[ 9]; \
      d[10] |= p[10]; d[11] |= p[11]; \
      d[12] |= p[12]; d[13] |= p[13]; \
      d[14] |= p[14]; d[15] |= p[15]; \
    } \
}
#endif

static bool crack_lm3(void *param) {
    uint32_t         h[2], l, r, t, u, *k;
    DES_key_schedule ks_tbl[7][256] __attribute__ ((aligned(32)));
    DES_key_schedule ks[7]          __attribute__ ((aligned(32)));
    crack_opt_t      *c=(crack_opt_t*)param;
    
    // precompute key schedules for alphabet
    DES_init_keys2(c->alphabet, ks_tbl);
        
    // perform initial permutation on ciphertext/hash
    h[0] = c->hash.w[0];
    h[1] = c->hash.w[1];
    IP(h[0], h[1]);
    h[0] = ROTATE(h[0], 29) & 0xffffffffL;
    h[1] = ROTATE(h[1], 29) & 0xffffffffL;

    // set the initial key schedules based on pwd_idx
    // initialize key schedules based on pwd_idx values
    for (int i=7; i>0; i--) {
      // if not set, skip it
      if (c->pwd_idx[i-1] == ~0UL) continue;
      // set key schedule for this index
      DES_SET_KEY(i);
    }

    goto compute_lm;

    do {
      DES_SET_KEY(7);
      do {
        DES_SET_KEY(6);
        do {
          DES_SET_KEY(5);
          do {
            DES_SET_KEY(4);
            do {
              DES_SET_KEY(3);
              do {
                DES_SET_KEY(2);
                do {
                  DES_SET_KEY(1);
compute_lm:
                  // permuted plaintext
                  r = 0x2400B807; l = 0xAA190747;

                  k = (uint32_t*)&ks[0];

                  // encrypt
                  DES_F(l, r,  0); DES_F(r, l,  2);
                  DES_F(l, r,  4); DES_F(r, l,  6);     
                  DES_F(l, r,  8); DES_F(r, l, 10);    
                  DES_F(l, r, 12); DES_F(r, l, 14);   
                  DES_F(l, r, 16); DES_F(r, l, 18);    
                  DES_F(l, r, 20); DES_F(r, l, 22);    
                  DES_F(l, r, 24); DES_F(r, l, 26);    
                  DES_F(l, r, 28);   

                  c->complete++;

                  // do we have one half of the LM hash?
                  if (h[0] == l) {
                    // apply the last round
                    DES_F(r, l, 30);
                    // do we have the full hash?
                    if (h[1] == r) {
                      // ok, we found the key
                      c->found = true;
                      return true;
                    }
                  }

                  if (--c->total_cbn == 0) return false;
                  if (c->stopped) return false;

                } while (++c->pwd_idx[0] < c->alpha_len);
                c->pwd_idx[0] = 0;
              } while (++c->pwd_idx[1] < c->alpha_len);
              c->pwd_idx[1] = 0;
            } while (++c->pwd_idx[2] < c->alpha_len);
            c->pwd_idx[2] = 0;
          } while (++c->pwd_idx[3] < c->alpha_len);
          c->pwd_idx[3] = 0;
        } while (++c->pwd_idx[4] < c->alpha_len);
        c->pwd_idx[4] = 0;
      } while (++c->pwd_idx[5] < c->alpha_len);
      c->pwd_idx[5] = 0;
    } while (++c->pwd_idx[6] < c->alpha_len);
    return false;
}

