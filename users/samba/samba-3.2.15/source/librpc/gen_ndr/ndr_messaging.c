/* parser auto-generated by pidl */

#include "includes.h"
#include "librpc/gen_ndr/ndr_messaging.h"

_PUBLIC_ enum ndr_err_code ndr_push_messaging_rec(struct ndr_push *ndr, int ndr_flags, const struct messaging_rec *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->msg_version));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->msg_type));
		NDR_CHECK(ndr_push_server_id(ndr, NDR_SCALARS, &r->dest));
		NDR_CHECK(ndr_push_server_id(ndr, NDR_SCALARS, &r->src));
		NDR_CHECK(ndr_push_DATA_BLOB(ndr, NDR_SCALARS, r->buf));
	}
	if (ndr_flags & NDR_BUFFERS) {
		NDR_CHECK(ndr_push_server_id(ndr, NDR_BUFFERS, &r->dest));
		NDR_CHECK(ndr_push_server_id(ndr, NDR_BUFFERS, &r->src));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_messaging_rec(struct ndr_pull *ndr, int ndr_flags, struct messaging_rec *r)
{
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->msg_version));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->msg_type));
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_SCALARS, &r->dest));
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_SCALARS, &r->src));
		NDR_CHECK(ndr_pull_DATA_BLOB(ndr, NDR_SCALARS, &r->buf));
	}
	if (ndr_flags & NDR_BUFFERS) {
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_BUFFERS, &r->dest));
		NDR_CHECK(ndr_pull_server_id(ndr, NDR_BUFFERS, &r->src));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_messaging_rec(struct ndr_print *ndr, const char *name, const struct messaging_rec *r)
{
	ndr_print_struct(ndr, name, "messaging_rec");
	ndr->depth++;
	ndr_print_uint32(ndr, "msg_version", r->msg_version);
	ndr_print_uint32(ndr, "msg_type", r->msg_type);
	ndr_print_server_id(ndr, "dest", &r->dest);
	ndr_print_server_id(ndr, "src", &r->src);
	ndr_print_DATA_BLOB(ndr, "buf", r->buf);
	ndr->depth--;
}

_PUBLIC_ enum ndr_err_code ndr_push_messaging_array(struct ndr_push *ndr, int ndr_flags, const struct messaging_array *r)
{
	uint32_t cntr_messages_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_messages));
		for (cntr_messages_0 = 0; cntr_messages_0 < r->num_messages; cntr_messages_0++) {
			NDR_CHECK(ndr_push_messaging_rec(ndr, NDR_SCALARS, &r->messages[cntr_messages_0]));
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
		for (cntr_messages_0 = 0; cntr_messages_0 < r->num_messages; cntr_messages_0++) {
			NDR_CHECK(ndr_push_messaging_rec(ndr, NDR_BUFFERS, &r->messages[cntr_messages_0]));
		}
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_messaging_array(struct ndr_pull *ndr, int ndr_flags, struct messaging_array *r)
{
	uint32_t cntr_messages_0;
	TALLOC_CTX *_mem_save_messages_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_messages));
		NDR_PULL_ALLOC_N(ndr, r->messages, r->num_messages);
		_mem_save_messages_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->messages, 0);
		for (cntr_messages_0 = 0; cntr_messages_0 < r->num_messages; cntr_messages_0++) {
			NDR_CHECK(ndr_pull_messaging_rec(ndr, NDR_SCALARS, &r->messages[cntr_messages_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_messages_0, 0);
	}
	if (ndr_flags & NDR_BUFFERS) {
		_mem_save_messages_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->messages, 0);
		for (cntr_messages_0 = 0; cntr_messages_0 < r->num_messages; cntr_messages_0++) {
			NDR_CHECK(ndr_pull_messaging_rec(ndr, NDR_BUFFERS, &r->messages[cntr_messages_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_messages_0, 0);
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_messaging_array(struct ndr_print *ndr, const char *name, const struct messaging_array *r)
{
	uint32_t cntr_messages_0;
	ndr_print_struct(ndr, name, "messaging_array");
	ndr->depth++;
	ndr_print_uint32(ndr, "num_messages", r->num_messages);
	ndr->print(ndr, "%s: ARRAY(%d)", "messages", (int)r->num_messages);
	ndr->depth++;
	for (cntr_messages_0=0;cntr_messages_0<r->num_messages;cntr_messages_0++) {
		char *idx_0=NULL;
		if (asprintf(&idx_0, "[%d]", cntr_messages_0) != -1) {
			ndr_print_messaging_rec(ndr, "messages", &r->messages[cntr_messages_0]);
			free(idx_0);
		}
	}
	ndr->depth--;
	ndr->depth--;
}

_PUBLIC_ enum ndr_err_code ndr_push_dbwrap_tdb2_changes(struct ndr_push *ndr, int ndr_flags, const struct dbwrap_tdb2_changes *r)
{
	uint32_t cntr_keys_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_push_align(ndr, 4));
		NDR_CHECK(ndr_push_charset(ndr, NDR_SCALARS, "TDB2", 4, sizeof(uint8_t), CH_DOS));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, 1));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, ndr_charset_length(r->name, CH_UTF8)));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, 0));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, ndr_charset_length(r->name, CH_UTF8)));
		NDR_CHECK(ndr_push_charset(ndr, NDR_SCALARS, r->name, ndr_charset_length(r->name, CH_UTF8), sizeof(uint8_t), CH_UTF8));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->old_seqnum));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->new_seqnum));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_changes));
		NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->num_keys));
		for (cntr_keys_0 = 0; cntr_keys_0 < r->num_keys; cntr_keys_0++) {
			NDR_CHECK(ndr_push_DATA_BLOB(ndr, NDR_SCALARS, r->keys[cntr_keys_0]));
		}
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_dbwrap_tdb2_changes(struct ndr_pull *ndr, int ndr_flags, struct dbwrap_tdb2_changes *r)
{
	uint32_t cntr_keys_0;
	TALLOC_CTX *_mem_save_keys_0;
	if (ndr_flags & NDR_SCALARS) {
		NDR_CHECK(ndr_pull_align(ndr, 4));
		NDR_CHECK(ndr_pull_charset(ndr, NDR_SCALARS, &r->magic_string, 4, sizeof(uint8_t), CH_DOS));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->magic_version));
		NDR_CHECK(ndr_pull_array_size(ndr, &r->name));
		NDR_CHECK(ndr_pull_array_length(ndr, &r->name));
		if (ndr_get_array_length(ndr, &r->name) > ndr_get_array_size(ndr, &r->name)) {
			return ndr_pull_error(ndr, NDR_ERR_ARRAY_SIZE, "Bad array size %u should exceed array length %u", ndr_get_array_size(ndr, &r->name), ndr_get_array_length(ndr, &r->name));
		}
		NDR_CHECK(ndr_check_string_terminator(ndr, ndr_get_array_length(ndr, &r->name), sizeof(uint8_t)));
		NDR_CHECK(ndr_pull_charset(ndr, NDR_SCALARS, &r->name, ndr_get_array_length(ndr, &r->name), sizeof(uint8_t), CH_UTF8));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->old_seqnum));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->new_seqnum));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_changes));
		NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->num_keys));
		NDR_PULL_ALLOC_N(ndr, r->keys, r->num_keys);
		_mem_save_keys_0 = NDR_PULL_GET_MEM_CTX(ndr);
		NDR_PULL_SET_MEM_CTX(ndr, r->keys, 0);
		for (cntr_keys_0 = 0; cntr_keys_0 < r->num_keys; cntr_keys_0++) {
			NDR_CHECK(ndr_pull_DATA_BLOB(ndr, NDR_SCALARS, &r->keys[cntr_keys_0]));
		}
		NDR_PULL_SET_MEM_CTX(ndr, _mem_save_keys_0, 0);
	}
	if (ndr_flags & NDR_BUFFERS) {
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_dbwrap_tdb2_changes(struct ndr_print *ndr, const char *name, const struct dbwrap_tdb2_changes *r)
{
	uint32_t cntr_keys_0;
	ndr_print_struct(ndr, name, "dbwrap_tdb2_changes");
	ndr->depth++;
	ndr_print_string(ndr, "magic_string", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?"TDB2":r->magic_string);
	ndr_print_uint32(ndr, "magic_version", (ndr->flags & LIBNDR_PRINT_SET_VALUES)?1:r->magic_version);
	ndr_print_string(ndr, "name", r->name);
	ndr_print_uint32(ndr, "old_seqnum", r->old_seqnum);
	ndr_print_uint32(ndr, "new_seqnum", r->new_seqnum);
	ndr_print_uint32(ndr, "num_changes", r->num_changes);
	ndr_print_uint32(ndr, "num_keys", r->num_keys);
	ndr->print(ndr, "%s: ARRAY(%d)", "keys", (int)r->num_keys);
	ndr->depth++;
	for (cntr_keys_0=0;cntr_keys_0<r->num_keys;cntr_keys_0++) {
		char *idx_0=NULL;
		if (asprintf(&idx_0, "[%d]", cntr_keys_0) != -1) {
			ndr_print_DATA_BLOB(ndr, "keys", r->keys[cntr_keys_0]);
			free(idx_0);
		}
	}
	ndr->depth--;
	ndr->depth--;
}
