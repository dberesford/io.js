
#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER node

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./node_lttng_tp.h"

#if !defined(__NODE_LTTNG_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define __NODE_LTTNG_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
  node,
  http_server_request,
  TP_ARGS(
    char*, url,
    char*, method,
    char*, forwardedFor
  ),
  TP_FIELDS(
    ctf_string(url, url)
    ctf_string(method, method)
    ctf_string(forwardedFor, forwardedFor)
  )
)

// DBTODO - sort out BYTE_ORDER issue with ints
TRACEPOINT_EVENT(
  node,
  http_server_response,
  TP_ARGS(
    char*, port,
    char*, remote,
    char*, fd
  ),
  TP_FIELDS(
    ctf_string(port, port)
    ctf_string(remote, remote)
    ctf_string(fd, fd)
  )
)

TRACEPOINT_EVENT(
  node,
  http_client_request,
  TP_ARGS(
    char*, url,
    char*, method
  ),
  TP_FIELDS(
    ctf_string(url, url)
    ctf_string(method, method)
  )
)

// DBTODO - sort out BYTE_ORDER issue with ints
TRACEPOINT_EVENT(
  node,
  http_client_response,
  TP_ARGS(
    char*, port,
    char*, remote,
    char*, fd
  ),
  TP_FIELDS(
    ctf_string(port, port)
    ctf_string(remote, remote)
    ctf_string(fd, fd)
  )
)

TRACEPOINT_EVENT(
  node,
  net_server_connection,
  TP_ARGS(
    char*, remote,          
    char*, port,
    char*, fd,
    char*, buffered
  ),
  TP_FIELDS(
    ctf_string(remote, remote)
    ctf_string(port, port)
    ctf_string(fd, fd)
    ctf_string(buffered, buffered)
  )
)

TRACEPOINT_EVENT(
  node,
  net_stream_end,
  TP_ARGS(
    char*, remote,          
    char*, port,
    char*, fd
  ),
  TP_FIELDS(
    ctf_string(remote, remote)
    ctf_string(port, port)
    ctf_string(fd, fd)
  )
)


TRACEPOINT_EVENT(
  node,
  gc_start,
  TP_ARGS(
    char*, gctype,
    char*, gcflags
  ),
  TP_FIELDS(
    ctf_string(gctype, gctype)
    ctf_string(gcflags, gcflags)
  )
)

TRACEPOINT_EVENT(
  node,
  gc_done,
  TP_ARGS(
    char*, gctype,
    char*, gcflags
  ),
  TP_FIELDS(
    ctf_string(gctype, gctype)
    ctf_string(gcflags, gcflags)
  )
)
    
#endif /* __NODE_LTTNG_TP_H */

#include <lttng/tracepoint-event.h>
