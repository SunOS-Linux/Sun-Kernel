{
	"xadd/w check unaligned stack",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_0, -8),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_W, BPF_ADD, BPF_REG_10, BPF_REG_0, -7),
=======
	BPF_STX_XADD(BPF_W, BPF_REG_10, BPF_REG_0, -7),
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_10, -8),
	BPF_EXIT_INSN(),
	},
	.result = REJECT,
	.errstr = "misaligned stack access off",
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
},
{
	"xadd/w check unaligned map",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 0, 1),
	BPF_EXIT_INSN(),
	BPF_MOV64_IMM(BPF_REG_1, 1),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_W, BPF_ADD, BPF_REG_0, BPF_REG_1, 3),
=======
	BPF_STX_XADD(BPF_W, BPF_REG_0, BPF_REG_1, 3),
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0, 3),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_8b = { 3 },
	.result = REJECT,
	.errstr = "misaligned value access off",
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
},
{
	"xadd/w check unaligned pkt",
	.insns = {
	BPF_LDX_MEM(BPF_W, BPF_REG_2, BPF_REG_1, offsetof(struct xdp_md, data)),
	BPF_LDX_MEM(BPF_W, BPF_REG_3, BPF_REG_1,
		    offsetof(struct xdp_md, data_end)),
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_2),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, 8),
	BPF_JMP_REG(BPF_JLT, BPF_REG_1, BPF_REG_3, 2),
	BPF_MOV64_IMM(BPF_REG_0, 99),
	BPF_JMP_IMM(BPF_JA, 0, 0, 6),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_ST_MEM(BPF_W, BPF_REG_2, 0, 0),
	BPF_ST_MEM(BPF_W, BPF_REG_2, 3, 0),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_W, BPF_ADD, BPF_REG_2, BPF_REG_0, 1),
	BPF_ATOMIC_OP(BPF_W, BPF_ADD, BPF_REG_2, BPF_REG_0, 2),
=======
	BPF_STX_XADD(BPF_W, BPF_REG_2, BPF_REG_0, 1),
	BPF_STX_XADD(BPF_W, BPF_REG_2, BPF_REG_0, 2),
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_2, 1),
	BPF_EXIT_INSN(),
	},
	.result = REJECT,
<<<<<<< HEAD
	.errstr = "BPF_ATOMIC stores into R2 pkt is not allowed",
=======
	.errstr = "BPF_XADD stores into R2 pkt is not allowed",
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	.prog_type = BPF_PROG_TYPE_XDP,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"xadd/w check whether src/dst got mangled, 1",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_0),
	BPF_MOV64_REG(BPF_REG_7, BPF_REG_10),
	BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_0, -8),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_DW, BPF_ADD, BPF_REG_10, BPF_REG_0, -8),
	BPF_ATOMIC_OP(BPF_DW, BPF_ADD, BPF_REG_10, BPF_REG_0, -8),
=======
	BPF_STX_XADD(BPF_DW, BPF_REG_10, BPF_REG_0, -8),
	BPF_STX_XADD(BPF_DW, BPF_REG_10, BPF_REG_0, -8),
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BPF_JMP_REG(BPF_JNE, BPF_REG_6, BPF_REG_0, 3),
	BPF_JMP_REG(BPF_JNE, BPF_REG_7, BPF_REG_10, 2),
	BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_10, -8),
	BPF_EXIT_INSN(),
	BPF_MOV64_IMM(BPF_REG_0, 42),
	BPF_EXIT_INSN(),
	},
	.result = ACCEPT,
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.retval = 3,
},
{
	"xadd/w check whether src/dst got mangled, 2",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_0),
	BPF_MOV64_REG(BPF_REG_7, BPF_REG_10),
	BPF_STX_MEM(BPF_W, BPF_REG_10, BPF_REG_0, -8),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_W, BPF_ADD, BPF_REG_10, BPF_REG_0, -8),
	BPF_ATOMIC_OP(BPF_W, BPF_ADD, BPF_REG_10, BPF_REG_0, -8),
=======
	BPF_STX_XADD(BPF_W, BPF_REG_10, BPF_REG_0, -8),
	BPF_STX_XADD(BPF_W, BPF_REG_10, BPF_REG_0, -8),
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BPF_JMP_REG(BPF_JNE, BPF_REG_6, BPF_REG_0, 3),
	BPF_JMP_REG(BPF_JNE, BPF_REG_7, BPF_REG_10, 2),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_10, -8),
	BPF_EXIT_INSN(),
	BPF_MOV64_IMM(BPF_REG_0, 42),
	BPF_EXIT_INSN(),
	},
	.result = ACCEPT,
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.retval = 3,
},
