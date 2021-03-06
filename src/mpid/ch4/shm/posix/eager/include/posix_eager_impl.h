/*
 *  (C) 2006 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 *  Portions of this code were written by Intel Corporation.
 *  Copyright (C) 2011-2017 Intel Corporation.  Intel provides this material
 *  to Argonne National Laboratory subject to Software Grant and Corporate
 *  Contributor License Agreement dated February 8, 2012.
 */
#ifndef POSIX_EAGER_IMPL_H_INCLUDED
#define POSIX_EAGER_IMPL_H_INCLUDED

#ifndef POSIX_EAGER_INLINE
#ifndef POSIX_EAGER_DISABLE_INLINES

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_eager_send(int grank,
                                                    MPIDI_POSIX_am_header_t ** msg_hdr,
                                                    struct iovec **iov, size_t * iov_num)
{
    return MPIDI_POSIX_eager_func->send(grank, msg_hdr, iov, iov_num);
}

MPL_STATIC_INLINE_PREFIX int MPIDI_POSIX_eager_recv_begin(MPIDI_POSIX_eager_recv_transaction_t *
                                                          transaction)
{
    return MPIDI_POSIX_eager_func->recv_begin(transaction);
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_memcpy(MPIDI_POSIX_eager_recv_transaction_t *
                                                            transaction, void *dst, const void *src,
                                                            size_t size)
{
    return MPIDI_POSIX_eager_func->recv_memcpy(transaction, dst, src, size);
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_commit(MPIDI_POSIX_eager_recv_transaction_t *
                                                            transaction)
{
    return MPIDI_POSIX_eager_func->recv_commit(transaction);
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_posted_hook(int grank)
{
    return MPIDI_POSIX_eager_func->recv_posted_hook(grank);
}

MPL_STATIC_INLINE_PREFIX void MPIDI_POSIX_eager_recv_completed_hook(int grank)
{
    return MPIDI_POSIX_eager_func->recv_completed_hook(grank);
}

#endif /* POSIX_EAGER_DISABLE_INLINES  */

#else /* POSIX_EAGER_INLINE */

#define __posix_eager_inline_stub__  0
#define __posix_eager_inline_fbox__  1
#define __posix_eager_inline_iqueue__  2

#if POSIX_EAGER_INLINE==__posix_eager_inline_stub__
#include "../stub/posix_eager_inline.h"
#elif POSIX_EAGER_INLINE==__posix_eager_inline_fbox__
#include "../fbox/posix_eager_inline.h"
#elif POSIX_EAGER_INLINE==__posix_eager_inline_iqueue__
#include "../iqueue/posix_eager_inline.h"
#else
#error "No direct posix eager included"
#endif

#endif /* POSIX_EAGER_INLINE */

#endif /* POSIX_EAGER_IMPL_H_INCLUDED */
