#include "cmake-build-debug/zlib-ng/zlib-ng.h"
#include <dragonruby.h>
#include <mruby/string.h>

mrb_value zlib_compress_string(mrb_state *mrb, mrb_value self) {
  struct RString *rstr = RSTRING(self);
  const char *str = RSTR_PTR(rstr);
  const size_t len = (size_t) RSTR_LEN(rstr);

  mrb_int level = 4;
  mrb_get_args(mrb, "|i", &level);

  if (level < 0 || level > 9) {
    mrb_raisef(mrb, E_ARGUMENT_ERROR, "expected `level` to be in the range 0..9, got %d", level);
  }

  size_t result_len = len + (len / 100);
  mrb_value new_str = mrb_str_new_capa(mrb, result_len);

  int32_t ec = zng_compress2((uint8_t *) RSTRING_PTR(new_str), &result_len, (uint8_t *) str, len, level);

  if (ec != Z_OK) {
    mrb_raisef(mrb, mrb->eStandardError_class, "couldn't compress string");
  }

  RSTR_SET_LEN(RSTRING(new_str), result_len);
  return new_str;
}

void drb_register_c_extensions_with_api(mrb_state *mrb, struct drb_api_t *api) {
  struct RClass *str = mrb->string_class;
  mrb_define_method_id(mrb, str, mrb_intern_lit(mrb, "compress"), zlib_compress_string, MRB_ARGS_OPT(1));
}