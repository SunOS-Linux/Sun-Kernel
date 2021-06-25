{
	"constant register |= constant should keep constant type",
	.insns = {
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -48),
	BPF_MOV64_IMM(BPF_REG_2, 34),
	BPF_ALU64_IMM(BPF_OR, BPF_REG_2, 13),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_EMIT_CALL(BPF_FUNC_probe_read_kernel),
	BPF_EXIT_INSN(),
	},
	.result = ACCEPT,
	.prog_type = BPF_PROG_TYPE_TRACEPOINT,
},
{
	"constant register |= constant should not bypass stack boundary checks",
	.insns = {
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -48),
	BPF_MOV64_IMM(BPF_REG_2, 34),
	BPF_ALU64_IMM(BPF_OR, BPF_REG_2, 24),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_EMIT_CALL(BPF_FUNC_probe_read_kernel),
	BPF_EXIT_INSN(),
	},
<<<<<<< HEAD
	.errstr = "invalid indirect access to stack R1 off=-48 size=58",
=======
	.errstr = "invalid stack type R1 off=-48 access_size=58",
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	.result = REJECT,
	.prog_type = BPF_PROG_TYPE_TRACEPOINT,
},
{
	"constant register |= constant register should keep constant type",
	.insns = {
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -48),
	BPF_MOV64_IMM(BPF_REG_2, 34),
	BPF_MOV64_IMM(BPF_REG_4, 13),
	BPF_ALU64_REG(BPF_OR, BPF_REG_2, BPF_REG_4),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_EMIT_CALL(BPF_FUNC_probe_read_kernel),
	BPF_EXIT_INSN(),
	},
	.result = ACCEPT,
	.prog_type = BPF_PROG_TYPE_TRACEPOINT,
},
{
	"constant register |= constant register should not bypass stack boundary checks",
	.insns = {
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -48),
	BPF_MOV64_IMM(BPF_REG_2, 34),
	BPF_MOV64_IMM(BPF_REG_4, 24),
	BPF_ALU64_REG(BPF_OR, BPF_REG_2, BPF_REG_4),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_EMIT_CALL(BPF_FUNC_probe_read_kernel),
	BPF_EXIT_INSN(),
	},
<<<<<<< HEAD
	.errstr = "invalid indirect access to stack R1 off=-48 size=58",
=======
	.errstr = "invalid stack type R1 off=-48 access_size=58",
>>>>>>> 482398af3c2fc5af953c5a3127ca167a01d0949b
	.result = REJECT,
	.prog_type = BPF_PROG_TYPE_TRACEPOINT,
},
