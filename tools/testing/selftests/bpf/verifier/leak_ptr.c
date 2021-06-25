{
	"leak pointer into ctx 1",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_STX_MEM(BPF_DW, BPF_REG_1, BPF_REG_0,
		    offsetof(struct __sk_buff, cb[0])),
	BPF_LD_MAP_FD(BPF_REG_2, 0),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_DW, BPF_ADD, BPF_REG_1, BPF_REG_2,
=======
	BPF_STX_XADD(BPF_DW, BPF_REG_1, BPF_REG_2,
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		      offsetof(struct __sk_buff, cb[0])),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_8b = { 2 },
	.errstr_unpriv = "R2 leaks addr into mem",
	.result_unpriv = REJECT,
	.result = REJECT,
<<<<<<< HEAD
	.errstr = "BPF_ATOMIC stores into R1 ctx is not allowed",
=======
	.errstr = "BPF_XADD stores into R1 ctx is not allowed",
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
},
{
	"leak pointer into ctx 2",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_STX_MEM(BPF_DW, BPF_REG_1, BPF_REG_0,
		    offsetof(struct __sk_buff, cb[0])),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_DW, BPF_ADD, BPF_REG_1, BPF_REG_10,
=======
	BPF_STX_XADD(BPF_DW, BPF_REG_1, BPF_REG_10,
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
		      offsetof(struct __sk_buff, cb[0])),
	BPF_EXIT_INSN(),
	},
	.errstr_unpriv = "R10 leaks addr into mem",
	.result_unpriv = REJECT,
	.result = REJECT,
<<<<<<< HEAD
	.errstr = "BPF_ATOMIC stores into R1 ctx is not allowed",
=======
	.errstr = "BPF_XADD stores into R1 ctx is not allowed",
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
},
{
	"leak pointer into ctx 3",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_LD_MAP_FD(BPF_REG_2, 0),
	BPF_STX_MEM(BPF_DW, BPF_REG_1, BPF_REG_2,
		      offsetof(struct __sk_buff, cb[0])),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_8b = { 1 },
	.errstr_unpriv = "R2 leaks addr into ctx",
	.result_unpriv = REJECT,
	.result = ACCEPT,
},
{
	"leak pointer into map val",
	.insns = {
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_STX_MEM(BPF_DW, BPF_REG_0, BPF_REG_3, 0),
<<<<<<< HEAD
	BPF_ATOMIC_OP(BPF_DW, BPF_ADD, BPF_REG_0, BPF_REG_6, 0),
=======
	BPF_STX_XADD(BPF_DW, BPF_REG_0, BPF_REG_6, 0),
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_8b = { 4 },
	.errstr_unpriv = "R6 leaks addr into mem",
	.result_unpriv = REJECT,
	.result = ACCEPT,
},
