// SPDX-License-Identifier: MIT
/*
 * Copyright © 2014 Intel Corporation
 */

#include <linux/circ_buf.h>

#include "gem/i915_gem_context.h"
<<<<<<< HEAD
#include "gt/gen8_engine_cs.h"
#include "gt/intel_breadcrumbs.h"
=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#include "gt/intel_context.h"
#include "gt/intel_engine_pm.h"
#include "gt/intel_gt.h"
#include "gt/intel_gt_pm.h"
<<<<<<< HEAD
#include "gt/intel_lrc.h"
#include "gt/intel_mocs.h"
=======
#include "gt/intel_lrc_reg.h"
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
#include "gt/intel_ring.h"

#include "intel_guc_submission.h"

#include "i915_drv.h"
#include "i915_trace.h"

/**
 * DOC: GuC-based command submission
 *
 * IMPORTANT NOTE: GuC submission is currently not supported in i915. The GuC
 * firmware is moving to an updated submission interface and we plan to
 * turn submission back on when that lands. The below documentation (and related
 * code) matches the old submission model and will be updated as part of the
 * upgrade to the new flow.
 *
 * GuC stage descriptor:
 * During initialization, the driver allocates a static pool of 1024 such
 * descriptors, and shares them with the GuC. Currently, we only use one
 * descriptor. This stage descriptor lets the GuC know about the workqueue and
 * process descriptor. Theoretically, it also lets the GuC know about our HW
 * contexts (context ID, etc...), but we actually employ a kind of submission
 * where the GuC uses the LRCA sent via the work item instead. This is called
 * a "proxy" submission.
 *
 * The Scratch registers:
 * There are 16 MMIO-based registers start from 0xC180. The kernel driver writes
 * a value to the action register (SOFT_SCRATCH_0) along with any data. It then
 * triggers an interrupt on the GuC via another register write (0xC4C8).
 * Firmware writes a success/fail code back to the action register after
 * processes the request. The kernel driver polls waiting for this update and
 * then proceeds.
 *
 * Work Items:
 * There are several types of work items that the host may place into a
 * workqueue, each with its own requirements and limitations. Currently only
 * WQ_TYPE_INORDER is needed to support legacy submission via GuC, which
 * represents in-order queue. The kernel driver packs ring tail pointer and an
 * ELSP context descriptor dword into Work Item.
 * See guc_add_request()
 *
 */

<<<<<<< HEAD
#define GUC_REQUEST_SIZE 64 /* bytes */

=======
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static inline struct i915_priolist *to_priolist(struct rb_node *rb)
{
	return rb_entry(rb, struct i915_priolist, node);
}

static struct guc_stage_desc *__get_stage_desc(struct intel_guc *guc, u32 id)
{
	struct guc_stage_desc *base = guc->stage_desc_pool_vaddr;

	return &base[id];
}

<<<<<<< HEAD
=======
static int guc_workqueue_create(struct intel_guc *guc)
{
	return intel_guc_allocate_and_map_vma(guc, GUC_WQ_SIZE, &guc->workqueue,
					      &guc->workqueue_vaddr);
}

static void guc_workqueue_destroy(struct intel_guc *guc)
{
	i915_vma_unpin_and_release(&guc->workqueue, I915_VMA_RELEASE_MAP);
}

/*
 * Initialise the process descriptor shared with the GuC firmware.
 */
static int guc_proc_desc_create(struct intel_guc *guc)
{
	const u32 size = PAGE_ALIGN(sizeof(struct guc_process_desc));

	return intel_guc_allocate_and_map_vma(guc, size, &guc->proc_desc,
					      &guc->proc_desc_vaddr);
}

static void guc_proc_desc_destroy(struct intel_guc *guc)
{
	i915_vma_unpin_and_release(&guc->proc_desc, I915_VMA_RELEASE_MAP);
}

static void guc_proc_desc_init(struct intel_guc *guc)
{
	struct guc_process_desc *desc;

	desc = memset(guc->proc_desc_vaddr, 0, sizeof(*desc));

	/*
	 * XXX: pDoorbell and WQVBaseAddress are pointers in process address
	 * space for ring3 clients (set them as in mmap_ioctl) or kernel
	 * space for kernel clients (map on demand instead? May make debug
	 * easier to have it mapped).
	 */
	desc->wq_base_addr = 0;
	desc->db_base_addr = 0;

	desc->wq_size_bytes = GUC_WQ_SIZE;
	desc->wq_status = WQ_STATUS_ACTIVE;
	desc->priority = GUC_CLIENT_PRIORITY_KMD_NORMAL;
}

static void guc_proc_desc_fini(struct intel_guc *guc)
{
	memset(guc->proc_desc_vaddr, 0, sizeof(struct guc_process_desc));
}

>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
static int guc_stage_desc_pool_create(struct intel_guc *guc)
{
	u32 size = PAGE_ALIGN(sizeof(struct guc_stage_desc) *
			      GUC_MAX_STAGE_DESCRIPTORS);

	return intel_guc_allocate_and_map_vma(guc, size, &guc->stage_desc_pool,
					      &guc->stage_desc_pool_vaddr);
}

static void guc_stage_desc_pool_destroy(struct intel_guc *guc)
{
	i915_vma_unpin_and_release(&guc->stage_desc_pool, I915_VMA_RELEASE_MAP);
}

/*
 * Initialise/clear the stage descriptor shared with the GuC firmware.
 *
 * This descriptor tells the GuC where (in GGTT space) to find the important
 * data structures related to work submission (process descriptor, write queue,
 * etc).
 */
static void guc_stage_desc_init(struct intel_guc *guc)
{
	struct guc_stage_desc *desc;

	/* we only use 1 stage desc, so hardcode it to 0 */
	desc = __get_stage_desc(guc, 0);
	memset(desc, 0, sizeof(*desc));

	desc->attribute = GUC_STAGE_DESC_ATTR_ACTIVE |
			  GUC_STAGE_DESC_ATTR_KERNEL;

	desc->stage_id = 0;
	desc->priority = GUC_CLIENT_PRIORITY_KMD_NORMAL;

<<<<<<< HEAD
=======
	desc->process_desc = intel_guc_ggtt_offset(guc, guc->proc_desc);
	desc->wq_addr = intel_guc_ggtt_offset(guc, guc->workqueue);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	desc->wq_size = GUC_WQ_SIZE;
}

static void guc_stage_desc_fini(struct intel_guc *guc)
{
	struct guc_stage_desc *desc;

	desc = __get_stage_desc(guc, 0);
	memset(desc, 0, sizeof(*desc));
}

<<<<<<< HEAD
static void guc_add_request(struct intel_guc *guc, struct i915_request *rq)
{
	/* Leaving stub as this function will be used in future patches */
=======
/* Construct a Work Item and append it to the GuC's Work Queue */
static void guc_wq_item_append(struct intel_guc *guc,
			       u32 target_engine, u32 context_desc,
			       u32 ring_tail, u32 fence_id)
{
	/* wqi_len is in DWords, and does not include the one-word header */
	const size_t wqi_size = sizeof(struct guc_wq_item);
	const u32 wqi_len = wqi_size / sizeof(u32) - 1;
	struct guc_process_desc *desc = guc->proc_desc_vaddr;
	struct guc_wq_item *wqi;
	u32 wq_off;

	lockdep_assert_held(&guc->wq_lock);

	/* For now workqueue item is 4 DWs; workqueue buffer is 2 pages. So we
	 * should not have the case where structure wqi is across page, neither
	 * wrapped to the beginning. This simplifies the implementation below.
	 *
	 * XXX: if not the case, we need save data to a temp wqi and copy it to
	 * workqueue buffer dw by dw.
	 */
	BUILD_BUG_ON(wqi_size != 16);

	/* We expect the WQ to be active if we're appending items to it */
	GEM_BUG_ON(desc->wq_status != WQ_STATUS_ACTIVE);

	/* Free space is guaranteed. */
	wq_off = READ_ONCE(desc->tail);
	GEM_BUG_ON(CIRC_SPACE(wq_off, READ_ONCE(desc->head),
			      GUC_WQ_SIZE) < wqi_size);
	GEM_BUG_ON(wq_off & (wqi_size - 1));

	wqi = guc->workqueue_vaddr + wq_off;

	/* Now fill in the 4-word work queue item */
	wqi->header = WQ_TYPE_INORDER |
		      (wqi_len << WQ_LEN_SHIFT) |
		      (target_engine << WQ_TARGET_SHIFT) |
		      WQ_NO_WCFLUSH_WAIT;
	wqi->context_desc = context_desc;
	wqi->submit_element_info = ring_tail << WQ_RING_TAIL_SHIFT;
	GEM_BUG_ON(ring_tail > WQ_RING_TAIL_MAX);
	wqi->fence_id = fence_id;

	/* Make the update visible to GuC */
	WRITE_ONCE(desc->tail, (wq_off + wqi_size) & (GUC_WQ_SIZE - 1));
}

static void guc_add_request(struct intel_guc *guc, struct i915_request *rq)
{
	struct intel_engine_cs *engine = rq->engine;
	u32 ctx_desc = rq->context->lrc.ccid;
	u32 ring_tail = intel_ring_set_tail(rq->ring, rq->tail) / sizeof(u64);

	guc_wq_item_append(guc, engine->guc_id, ctx_desc,
			   ring_tail, rq->fence.seqno);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

/*
 * When we're doing submissions using regular execlists backend, writing to
 * ELSP from CPU side is enough to make sure that writes to ringbuffer pages
 * pinned in mappable aperture portion of GGTT are visible to command streamer.
 * Writes done by GuC on our behalf are not guaranteeing such ordering,
 * therefore, to ensure the flush, we're issuing a POSTING READ.
 */
static void flush_ggtt_writes(struct i915_vma *vma)
{
	if (i915_vma_is_map_and_fenceable(vma))
		intel_uncore_posting_read_fw(vma->vm->gt->uncore,
					     GUC_STATUS);
}

static void guc_submit(struct intel_engine_cs *engine,
		       struct i915_request **out,
		       struct i915_request **end)
{
	struct intel_guc *guc = &engine->gt->uc.guc;

<<<<<<< HEAD
=======
	spin_lock(&guc->wq_lock);

>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	do {
		struct i915_request *rq = *out++;

		flush_ggtt_writes(rq->ring->vma);
		guc_add_request(guc, rq);
	} while (out != end);
<<<<<<< HEAD
=======

	spin_unlock(&guc->wq_lock);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

static inline int rq_prio(const struct i915_request *rq)
{
	return rq->sched.attr.priority;
}

static struct i915_request *schedule_in(struct i915_request *rq, int idx)
{
	trace_i915_request_in(rq, idx);

	/*
	 * Currently we are not tracking the rq->context being inflight
	 * (ce->inflight = rq->engine). It is only used by the execlists
	 * backend at the moment, a similar counting strategy would be
	 * required if we generalise the inflight tracking.
	 */

	__intel_gt_pm_get(rq->engine->gt);
	return i915_request_get(rq);
}

static void schedule_out(struct i915_request *rq)
{
	trace_i915_request_out(rq);

	intel_gt_pm_put_async(rq->engine->gt);
	i915_request_put(rq);
}

static void __guc_dequeue(struct intel_engine_cs *engine)
{
	struct intel_engine_execlists * const execlists = &engine->execlists;
	struct i915_request **first = execlists->inflight;
	struct i915_request ** const last_port = first + execlists->port_mask;
	struct i915_request *last = first[0];
	struct i915_request **port;
	bool submit = false;
	struct rb_node *rb;

	lockdep_assert_held(&engine->active.lock);

	if (last) {
		if (*++first)
			return;

		last = NULL;
	}

	/*
	 * We write directly into the execlists->inflight queue and don't use
	 * the execlists->pending queue, as we don't have a distinct switch
	 * event.
	 */
	port = first;
	while ((rb = rb_first_cached(&execlists->queue))) {
		struct i915_priolist *p = to_priolist(rb);
		struct i915_request *rq, *rn;
		int i;

		priolist_for_each_request_consume(rq, rn, p, i) {
			if (last && rq->context != last->context) {
				if (port == last_port)
					goto done;

				*port = schedule_in(last,
						    port - execlists->inflight);
				port++;
			}

			list_del_init(&rq->sched.link);
			__i915_request_submit(rq);
			submit = true;
			last = rq;
		}

		rb_erase_cached(&p->node, &execlists->queue);
		i915_priolist_free(p);
	}
done:
	execlists->queue_priority_hint =
		rb ? to_priolist(rb)->priority : INT_MIN;
	if (submit) {
		*port = schedule_in(last, port - execlists->inflight);
		*++port = NULL;
		guc_submit(engine, first, port);
	}
	execlists->active = execlists->inflight;
}

static void guc_submission_tasklet(unsigned long data)
{
	struct intel_engine_cs * const engine = (struct intel_engine_cs *)data;
	struct intel_engine_execlists * const execlists = &engine->execlists;
	struct i915_request **port, *rq;
	unsigned long flags;

	spin_lock_irqsave(&engine->active.lock, flags);

	for (port = execlists->inflight; (rq = *port); port++) {
		if (!i915_request_completed(rq))
			break;

		schedule_out(rq);
	}
	if (port != execlists->inflight) {
		int idx = port - execlists->inflight;
		int rem = ARRAY_SIZE(execlists->inflight) - idx;
		memmove(execlists->inflight, port, rem * sizeof(*port));
	}

	__guc_dequeue(engine);

	spin_unlock_irqrestore(&engine->active.lock, flags);
}

static void guc_reset_prepare(struct intel_engine_cs *engine)
{
	struct intel_engine_execlists * const execlists = &engine->execlists;

	ENGINE_TRACE(engine, "\n");

	/*
	 * Prevent request submission to the hardware until we have
	 * completed the reset in i915_gem_reset_finish(). If a request
	 * is completed by one engine, it may then queue a request
	 * to a second via its execlists->tasklet *just* as we are
	 * calling engine->init_hw() and also writing the ELSP.
	 * Turning off the execlists->tasklet until the reset is over
	 * prevents the race.
	 */
	__tasklet_disable_sync_once(&execlists->tasklet);
}

<<<<<<< HEAD
static void guc_reset_state(struct intel_context *ce,
			    struct intel_engine_cs *engine,
			    u32 head,
			    bool scrub)
{
	GEM_BUG_ON(!intel_context_is_pinned(ce));

	/*
	 * We want a simple context + ring to execute the breadcrumb update.
	 * We cannot rely on the context being intact across the GPU hang,
	 * so clear it and rebuild just what we need for the breadcrumb.
	 * All pending requests for this context will be zapped, and any
	 * future request will be after userspace has had the opportunity
	 * to recreate its own state.
	 */
	if (scrub)
		lrc_init_regs(ce, engine, true);

	/* Rerun the request; its payload has been neutered (if guilty). */
	lrc_update_regs(ce, engine, head);
=======
static void
cancel_port_requests(struct intel_engine_execlists * const execlists)
{
	struct i915_request * const *port, *rq;

	/* Note we are only using the inflight and not the pending queue */

	for (port = execlists->active; (rq = *port); port++)
		schedule_out(rq);
	execlists->active =
		memset(execlists->inflight, 0, sizeof(execlists->inflight));
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

static void guc_reset_rewind(struct intel_engine_cs *engine, bool stalled)
{
	struct intel_engine_execlists * const execlists = &engine->execlists;
	struct i915_request *rq;
	unsigned long flags;

	spin_lock_irqsave(&engine->active.lock, flags);

<<<<<<< HEAD
=======
	cancel_port_requests(execlists);

>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	/* Push back any incomplete requests for replay after the reset. */
	rq = execlists_unwind_incomplete_requests(execlists);
	if (!rq)
		goto out_unlock;

	if (!i915_request_started(rq))
		stalled = false;

	__i915_request_reset(rq, stalled);
<<<<<<< HEAD
	guc_reset_state(rq->context, engine, rq->head, stalled);
=======
	intel_lr_context_reset(engine, rq->context, rq->head, stalled);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

out_unlock:
	spin_unlock_irqrestore(&engine->active.lock, flags);
}

static void guc_reset_cancel(struct intel_engine_cs *engine)
{
	struct intel_engine_execlists * const execlists = &engine->execlists;
	struct i915_request *rq, *rn;
	struct rb_node *rb;
	unsigned long flags;

	ENGINE_TRACE(engine, "\n");

	/*
	 * Before we call engine->cancel_requests(), we should have exclusive
	 * access to the submission state. This is arranged for us by the
	 * caller disabling the interrupt generation, the tasklet and other
	 * threads that may then access the same state, giving us a free hand
	 * to reset state. However, we still need to let lockdep be aware that
	 * we know this state may be accessed in hardirq context, so we
	 * disable the irq around this manipulation and we want to keep
	 * the spinlock focused on its duties and not accidentally conflate
	 * coverage to the submission's irq state. (Similarly, although we
	 * shouldn't need to disable irq around the manipulation of the
	 * submission's irq state, we also wish to remind ourselves that
	 * it is irq state.)
	 */
	spin_lock_irqsave(&engine->active.lock, flags);

<<<<<<< HEAD
=======
	/* Cancel the requests on the HW and clear the ELSP tracker. */
	cancel_port_requests(execlists);

>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	/* Mark all executing requests as skipped. */
	list_for_each_entry(rq, &engine->active.requests, sched.link) {
		i915_request_set_error_once(rq, -EIO);
		i915_request_mark_complete(rq);
	}

	/* Flush the queued requests to the timeline list (for retiring). */
	while ((rb = rb_first_cached(&execlists->queue))) {
		struct i915_priolist *p = to_priolist(rb);
		int i;

		priolist_for_each_request_consume(rq, rn, p, i) {
			list_del_init(&rq->sched.link);
			__i915_request_submit(rq);
			dma_fence_set_error(&rq->fence, -EIO);
			i915_request_mark_complete(rq);
		}

		rb_erase_cached(&p->node, &execlists->queue);
		i915_priolist_free(p);
	}

	/* Remaining _unready_ requests will be nop'ed when submitted */

	execlists->queue_priority_hint = INT_MIN;
	execlists->queue = RB_ROOT_CACHED;

	spin_unlock_irqrestore(&engine->active.lock, flags);
}

static void guc_reset_finish(struct intel_engine_cs *engine)
{
	struct intel_engine_execlists * const execlists = &engine->execlists;

	if (__tasklet_enable(&execlists->tasklet))
		/* And kick in case we missed a new request submission. */
		tasklet_hi_schedule(&execlists->tasklet);

	ENGINE_TRACE(engine, "depth->%d\n",
		     atomic_read(&execlists->tasklet.count));
}

/*
<<<<<<< HEAD
=======
 * Everything below here is concerned with setup & teardown, and is
 * therefore not part of the somewhat time-critical batch-submission
 * path of guc_submit() above.
 */

/*
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
 * Set up the memory resources to be shared with the GuC (via the GGTT)
 * at firmware loading time.
 */
int intel_guc_submission_init(struct intel_guc *guc)
{
	int ret;

	if (guc->stage_desc_pool)
		return 0;

	ret = guc_stage_desc_pool_create(guc);
	if (ret)
		return ret;
	/*
	 * Keep static analysers happy, let them know that we allocated the
	 * vma after testing that it didn't exist earlier.
	 */
	GEM_BUG_ON(!guc->stage_desc_pool);

<<<<<<< HEAD
	return 0;
=======
	ret = guc_workqueue_create(guc);
	if (ret)
		goto err_pool;

	ret = guc_proc_desc_create(guc);
	if (ret)
		goto err_workqueue;

	spin_lock_init(&guc->wq_lock);

	return 0;

err_workqueue:
	guc_workqueue_destroy(guc);
err_pool:
	guc_stage_desc_pool_destroy(guc);
	return ret;
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

void intel_guc_submission_fini(struct intel_guc *guc)
{
	if (guc->stage_desc_pool) {
<<<<<<< HEAD
=======
		guc_proc_desc_destroy(guc);
		guc_workqueue_destroy(guc);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		guc_stage_desc_pool_destroy(guc);
	}
}

static void guc_interrupts_capture(struct intel_gt *gt)
{
	struct intel_uncore *uncore = gt->uncore;
	u32 irqs = GT_CONTEXT_SWITCH_INTERRUPT;
	u32 dmask = irqs << 16 | irqs;

	GEM_BUG_ON(INTEL_GEN(gt->i915) < 11);

	/* Don't handle the ctx switch interrupt in GuC submission mode */
	intel_uncore_rmw(uncore, GEN11_RENDER_COPY_INTR_ENABLE, dmask, 0);
	intel_uncore_rmw(uncore, GEN11_VCS_VECS_INTR_ENABLE, dmask, 0);
}

static void guc_interrupts_release(struct intel_gt *gt)
{
	struct intel_uncore *uncore = gt->uncore;
	u32 irqs = GT_CONTEXT_SWITCH_INTERRUPT;
	u32 dmask = irqs << 16 | irqs;

	GEM_BUG_ON(INTEL_GEN(gt->i915) < 11);

	/* Handle ctx switch interrupts again */
	intel_uncore_rmw(uncore, GEN11_RENDER_COPY_INTR_ENABLE, 0, dmask);
	intel_uncore_rmw(uncore, GEN11_VCS_VECS_INTR_ENABLE, 0, dmask);
}

<<<<<<< HEAD
static int guc_context_alloc(struct intel_context *ce)
{
	return lrc_alloc(ce, ce->engine);
}

static int guc_context_pre_pin(struct intel_context *ce,
			       struct i915_gem_ww_ctx *ww,
			       void **vaddr)
{
	return lrc_pre_pin(ce, ce->engine, ww, vaddr);
}

static int guc_context_pin(struct intel_context *ce, void *vaddr)
{
	return lrc_pin(ce, ce->engine, vaddr);
}

static const struct intel_context_ops guc_context_ops = {
	.alloc = guc_context_alloc,

	.pre_pin = guc_context_pre_pin,
	.pin = guc_context_pin,
	.unpin = lrc_unpin,
	.post_unpin = lrc_post_unpin,

	.enter = intel_context_enter_engine,
	.exit = intel_context_exit_engine,

	.reset = lrc_reset,
	.destroy = lrc_destroy,
};

static int guc_request_alloc(struct i915_request *request)
{
	int ret;

	GEM_BUG_ON(!intel_context_is_pinned(request->context));

	/*
	 * Flush enough space to reduce the likelihood of waiting after
	 * we start building the request - in which case we will just
	 * have to repeat work.
	 */
	request->reserved_space += GUC_REQUEST_SIZE;

	/*
	 * Note that after this point, we have committed to using
	 * this request as it is being used to both track the
	 * state of engine initialisation and liveness of the
	 * golden renderstate above. Think twice before you try
	 * to cancel/unwind this request now.
	 */

	/* Unconditionally invalidate GPU caches and TLBs. */
	ret = request->engine->emit_flush(request, EMIT_INVALIDATE);
	if (ret)
		return ret;

	request->reserved_space -= GUC_REQUEST_SIZE;
	return 0;
}

static inline void queue_request(struct intel_engine_cs *engine,
				 struct i915_request *rq,
				 int prio)
{
	GEM_BUG_ON(!list_empty(&rq->sched.link));
	list_add_tail(&rq->sched.link,
		      i915_sched_lookup_priolist(engine, prio));
	set_bit(I915_FENCE_FLAG_PQUEUE, &rq->fence.flags);
}

static void guc_submit_request(struct i915_request *rq)
{
	struct intel_engine_cs *engine = rq->engine;
	unsigned long flags;

	/* Will be called from irq-context when using foreign fences. */
	spin_lock_irqsave(&engine->active.lock, flags);

	queue_request(engine, rq, rq_prio(rq));

	GEM_BUG_ON(RB_EMPTY_ROOT(&engine->execlists.queue.rb_root));
	GEM_BUG_ON(list_empty(&rq->sched.link));

	tasklet_hi_schedule(&engine->execlists.tasklet);

	spin_unlock_irqrestore(&engine->active.lock, flags);
}

static void sanitize_hwsp(struct intel_engine_cs *engine)
{
	struct intel_timeline *tl;

	list_for_each_entry(tl, &engine->status_page.timelines, engine_link)
		intel_timeline_reset_seqno(tl);
}

static void guc_sanitize(struct intel_engine_cs *engine)
{
	/*
	 * Poison residual state on resume, in case the suspend didn't!
	 *
	 * We have to assume that across suspend/resume (or other loss
	 * of control) that the contents of our pinned buffers has been
	 * lost, replaced by garbage. Since this doesn't always happen,
	 * let's poison such state so that we more quickly spot when
	 * we falsely assume it has been preserved.
	 */
	if (IS_ENABLED(CONFIG_DRM_I915_DEBUG_GEM))
		memset(engine->status_page.addr, POISON_INUSE, PAGE_SIZE);

	/*
	 * The kernel_context HWSP is stored in the status_page. As above,
	 * that may be lost on resume/initialisation, and so we need to
	 * reset the value in the HWSP.
	 */
	sanitize_hwsp(engine);

	/* And scrub the dirty cachelines for the HWSP */
	clflush_cache_range(engine->status_page.addr, PAGE_SIZE);
}

static void setup_hwsp(struct intel_engine_cs *engine)
{
	intel_engine_set_hwsp_writemask(engine, ~0u); /* HWSTAM */

	ENGINE_WRITE_FW(engine,
			RING_HWS_PGA,
			i915_ggtt_offset(engine->status_page.vma));
}

static void start_engine(struct intel_engine_cs *engine)
{
	ENGINE_WRITE_FW(engine,
			RING_MODE_GEN7,
			_MASKED_BIT_ENABLE(GEN11_GFX_DISABLE_LEGACY_MODE));

	ENGINE_WRITE_FW(engine, RING_MI_MODE, _MASKED_BIT_DISABLE(STOP_RING));
	ENGINE_POSTING_READ(engine, RING_MI_MODE);
}

static int guc_resume(struct intel_engine_cs *engine)
{
	assert_forcewakes_active(engine->uncore, FORCEWAKE_ALL);

	intel_mocs_init_engine(engine);

	intel_breadcrumbs_reset(engine->breadcrumbs);

	setup_hwsp(engine);
	start_engine(engine);

	return 0;
}

static void guc_set_default_submission(struct intel_engine_cs *engine)
{
	engine->submit_request = guc_submit_request;
	engine->schedule = i915_schedule;
	engine->execlists.tasklet.func = guc_submission_tasklet;

=======
static void guc_set_default_submission(struct intel_engine_cs *engine)
{
	/*
	 * We inherit a bunch of functions from execlists that we'd like
	 * to keep using:
	 *
	 *    engine->submit_request = execlists_submit_request;
	 *    engine->cancel_requests = execlists_cancel_requests;
	 *    engine->schedule = execlists_schedule;
	 *
	 * But we need to override the actual submission backend in order
	 * to talk to the GuC.
	 */
	intel_execlists_set_default_submission(engine);

	engine->execlists.tasklet.func = guc_submission_tasklet;

	/* do not use execlists park/unpark */
	engine->park = engine->unpark = NULL;

>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	engine->reset.prepare = guc_reset_prepare;
	engine->reset.rewind = guc_reset_rewind;
	engine->reset.cancel = guc_reset_cancel;
	engine->reset.finish = guc_reset_finish;

<<<<<<< HEAD
	engine->flags |= I915_ENGINE_NEEDS_BREADCRUMB_TASKLET;
	engine->flags |= I915_ENGINE_HAS_PREEMPTION;

	/*
	 * TODO: GuC supports timeslicing and semaphores as well, but they're
	 * handled by the firmware so some minor tweaks are required before
	 * enabling.
	 *
	 * engine->flags |= I915_ENGINE_HAS_TIMESLICES;
	 * engine->flags |= I915_ENGINE_HAS_SEMAPHORES;
	 */

	engine->emit_bb_start = gen8_emit_bb_start;
=======
	engine->flags &= ~I915_ENGINE_SUPPORTS_STATS;
	engine->flags |= I915_ENGINE_NEEDS_BREADCRUMB_TASKLET;
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b

	/*
	 * For the breadcrumb irq to work we need the interrupts to stay
	 * enabled. However, on all platforms on which we'll have support for
	 * GuC submission we don't allow disabling the interrupts at runtime, so
	 * we're always safe with the current flow.
	 */
	GEM_BUG_ON(engine->irq_enable || engine->irq_disable);
}

<<<<<<< HEAD
static void guc_release(struct intel_engine_cs *engine)
{
	engine->sanitize = NULL; /* no longer in control, nothing to sanitize */

	tasklet_kill(&engine->execlists.tasklet);

	intel_engine_cleanup_common(engine);
	lrc_fini_wa_ctx(engine);
}

static void guc_default_vfuncs(struct intel_engine_cs *engine)
{
	/* Default vfuncs which can be overridden by each engine. */

	engine->resume = guc_resume;

	engine->cops = &guc_context_ops;
	engine->request_alloc = guc_request_alloc;

	engine->emit_flush = gen8_emit_flush_xcs;
	engine->emit_init_breadcrumb = gen8_emit_init_breadcrumb;
	engine->emit_fini_breadcrumb = gen8_emit_fini_breadcrumb_xcs;
	if (INTEL_GEN(engine->i915) >= 12) {
		engine->emit_fini_breadcrumb = gen12_emit_fini_breadcrumb_xcs;
		engine->emit_flush = gen12_emit_flush_xcs;
	}
	engine->set_default_submission = guc_set_default_submission;
}

static void rcs_submission_override(struct intel_engine_cs *engine)
{
	switch (INTEL_GEN(engine->i915)) {
	case 12:
		engine->emit_flush = gen12_emit_flush_rcs;
		engine->emit_fini_breadcrumb = gen12_emit_fini_breadcrumb_rcs;
		break;
	case 11:
		engine->emit_flush = gen11_emit_flush_rcs;
		engine->emit_fini_breadcrumb = gen11_emit_fini_breadcrumb_rcs;
		break;
	default:
		engine->emit_flush = gen8_emit_flush_rcs;
		engine->emit_fini_breadcrumb = gen8_emit_fini_breadcrumb_rcs;
		break;
	}
}

static inline void guc_default_irqs(struct intel_engine_cs *engine)
{
	engine->irq_keep_mask = GT_RENDER_USER_INTERRUPT;
}

int intel_guc_submission_setup(struct intel_engine_cs *engine)
{
	struct drm_i915_private *i915 = engine->i915;

	/*
	 * The setup relies on several assumptions (e.g. irqs always enabled)
	 * that are only valid on gen11+
	 */
	GEM_BUG_ON(INTEL_GEN(i915) < 11);

	tasklet_init(&engine->execlists.tasklet,
		     guc_submission_tasklet, (unsigned long)engine);

	guc_default_vfuncs(engine);
	guc_default_irqs(engine);

	if (engine->class == RENDER_CLASS)
		rcs_submission_override(engine);

	lrc_init_wa_ctx(engine);

	/* Finally, take ownership and responsibility for cleanup! */
	engine->sanitize = guc_sanitize;
	engine->release = guc_release;

	return 0;
}

void intel_guc_submission_enable(struct intel_guc *guc)
{
	guc_stage_desc_init(guc);

	/* Take over from manual control of ELSP (execlists) */
	guc_interrupts_capture(guc_to_gt(guc));
=======
void intel_guc_submission_enable(struct intel_guc *guc)
{
	struct intel_gt *gt = guc_to_gt(guc);
	struct intel_engine_cs *engine;
	enum intel_engine_id id;

	/*
	 * We're using GuC work items for submitting work through GuC. Since
	 * we're coalescing multiple requests from a single context into a
	 * single work item prior to assigning it to execlist_port, we can
	 * never have more work items than the total number of ports (for all
	 * engines). The GuC firmware is controlling the HEAD of work queue,
	 * and it is guaranteed that it will remove the work item from the
	 * queue before our request is completed.
	 */
	BUILD_BUG_ON(ARRAY_SIZE(engine->execlists.inflight) *
		     sizeof(struct guc_wq_item) *
		     I915_NUM_ENGINES > GUC_WQ_SIZE);

	guc_proc_desc_init(guc);
	guc_stage_desc_init(guc);

	/* Take over from manual control of ELSP (execlists) */
	guc_interrupts_capture(gt);

	for_each_engine(engine, gt, id) {
		engine->set_default_submission = guc_set_default_submission;
		engine->set_default_submission(engine);
	}
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

void intel_guc_submission_disable(struct intel_guc *guc)
{
	struct intel_gt *gt = guc_to_gt(guc);

	GEM_BUG_ON(gt->awake); /* GT should be parked first */

	/* Note: By the time we're here, GuC may have already been reset */

	guc_interrupts_release(gt);

	guc_stage_desc_fini(guc);
<<<<<<< HEAD
=======
	guc_proc_desc_fini(guc);
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
}

static bool __guc_submission_selected(struct intel_guc *guc)
{
	struct drm_i915_private *i915 = guc_to_gt(guc)->i915;

	if (!intel_guc_submission_is_supported(guc))
		return false;

	return i915->params.enable_guc & ENABLE_GUC_SUBMISSION;
}

void intel_guc_submission_init_early(struct intel_guc *guc)
{
	guc->submission_selected = __guc_submission_selected(guc);
}

bool intel_engine_in_guc_submission_mode(const struct intel_engine_cs *engine)
{
	return engine->set_default_submission == guc_set_default_submission;
}
