/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef NETSTACKLAT_H
#define NETSTACKLAT_H

// Histograms support values up to 2^30 ns-> 1s
// 2^37 =~ 137sec max
#define HIST_MAX_LATENCY_SLOT 37
/*
 * MAX_LATENCY_SLOT + 1 bin for hist, +1 "bin" for the "sum key"
 * (https://github.com/cloudflare/ebpf_exporter?tab=readme-ov-file#sum-keys)
 * that ebpf_exporter expects for exp2 hists, see the _increment_histogram
 * macro in maps.bpf.h.
 */
#define HIST_NBINS (HIST_MAX_LATENCY_SLOT + 2)

#define NS_PER_S 1000000000
#define NS_PER_MS 1000000

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

#ifndef max
#define max(a, b)                   \
	({                          \
		typeof(a) _a = (a); \
		typeof(b) _b = (b); \
		_a > _b ? _a : _b;  \
	})
#endif

enum netstacklat_hook {
	NETSTACKLAT_HOOK_INVALID = 0,
	NETSTACKLAT_HOOK_IP_RCV,
	NETSTACKLAT_HOOK_CONNTRACK,
	NETSTACKLAT_HOOK_TCP_START,
	NETSTACKLAT_HOOK_UDP_START,
	NETSTACKLAT_HOOK_TCP_SOCK_QUEUE,
	NETSTACKLAT_HOOK_UDP_SOCK_QUEUE,
	NETSTACKLAT_HOOK_TCP_SOCK_READ,
	NETSTACKLAT_HOOK_UDP_SOCK_READ,
	NETSTACKLAT_HOOK_SOCK_STANDINGQUEUE,
	NETSTACKLAT_N_HOOKS,
};

struct netstacklat_bpf_config
{
	__u64 interval;
	__u64 target;
	bool persist_through_empty;
};

#endif
