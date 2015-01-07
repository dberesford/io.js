#ifndef SRC_NODE_LTTNG_PROVIDER_H_
#define SRC_NODE_LTTNG_PROVIDER_H_

#include "node_lttng_tp.h"

namespace node {
 
void NODE_HTTP_SERVER_REQUEST(node_lttng_http_server_request_t* req,
    node_lttng_connection_t* conn, const char *remote, int port,
    const char *method, const char *url, int fd) {
  tracepoint(node, http_server_request, req->url, req->method, req->forwardedFor);
}

void NODE_HTTP_SERVER_RESPONSE(node_lttng_connection_t* conn,
    const char *remote, int port, int fd) {
  // DBTODO - sort out problem with ctf_integer!
  char p[10];
  snprintf(p, sizeof(p), "%d", port);
  char f[10];
  snprintf(f, sizeof(p), "%d", fd);
  tracepoint(node, http_server_response, p, conn->remote, f);
}


void NODE_HTTP_CLIENT_REQUEST(node_lttng_http_client_request_t* req,
    node_lttng_connection_t* conn, const char *remote, int port,
    const char *method, const char *url, int fd) {
  tracepoint(node, http_client_request, req->url, req->method);
}


void NODE_HTTP_CLIENT_RESPONSE(node_lttng_connection_t* conn,
    const char *remote, int port, int fd) {
  // DBTODO - sort out problem with ctf_integer!
  char p[10];
  snprintf(p, sizeof(p), "%d", port);
  char f[10];
  snprintf(f, sizeof(p), "%d", fd);
  tracepoint(node, http_client_response, p, conn->remote, f);
}


void NODE_NET_SERVER_CONNECTION(node_lttng_connection_t* conn,
    const char *remote, int port, int fd) {
  // DBTODO - sort out problem with ctf_integer!
  char p[10];
  snprintf(p, sizeof(p), "%d", port);
  char f[10];
  snprintf(f, sizeof(p), "%d", fd);
  char b[10];
  snprintf(b, sizeof(p), "%d", conn->buffered);
  tracepoint(node, net_server_connection, conn->remote, p, f, b);
}


void NODE_NET_STREAM_END(node_lttng_connection_t* conn,
    const char *remote, int port, int fd) {
  // DBTODO - sort out problem with ctf_integer!
  char p[10];
  snprintf(p, sizeof(p), "%d", port);
  char f[10];
  snprintf(f, sizeof(p), "%d", fd);
  tracepoint(node, net_stream_end, conn->remote, p, f);
}


void NODE_GC_START(v8::GCType type,
                   v8::GCCallbackFlags flags,
                   v8::Isolate* isolate) {
  tracepoint(node, gc_start, "",""); // DBTODO
}


void NODE_GC_DONE(v8::GCType type,
                  v8::GCCallbackFlags flags,
                  v8::Isolate* isolate) {
  tracepoint(node, gc_done, "", ""); // DBTODO
}

bool NODE_HTTP_SERVER_REQUEST_ENABLED() { return true; }
bool NODE_HTTP_SERVER_RESPONSE_ENABLED() { return true; }
bool NODE_HTTP_CLIENT_REQUEST_ENABLED() { return true; }
bool NODE_HTTP_CLIENT_RESPONSE_ENABLED() { return true; }
bool NODE_NET_SERVER_CONNECTION_ENABLED() { return true; }
bool NODE_NET_STREAM_END_ENABLED() { return true; }

}  // namespace node

#endif  // SRC_NODE_LTTNG_PROVIDER_H_
