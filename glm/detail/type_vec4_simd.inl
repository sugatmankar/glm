/// @ref core
/// @file glm/detail/type_tvec4_sse2.inl

#if GLM_ARCH & GLM_ARCH_SSE2

namespace glm{
namespace detail
{
	template <precision P>
	struct compute_vec4_add<float, P>
	{
		static tvec4<float, P> call(tvec4<float, P> const & a, tvec4<float, P> const & b)
		{
			tvec4<float, P> Result(uninitialize);
			Result.data = _mm_add_ps(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_sub<float, P>
	{
		static tvec4<float, P> call(tvec4<float, P> const & a, tvec4<float, P> const & b)
		{
			tvec4<float, P> Result(uninitialize);
			Result.data = _mm_sub_ps(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_mul<float, P>
	{
		static tvec4<float, P> call(tvec4<float, P> const & a, tvec4<float, P> const & b)
		{
			tvec4<float, P> Result(uninitialize);
			Result.data = _mm_mul_ps(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_div<float, P>
	{
		static tvec4<float, P> call(tvec4<float, P> const & a, tvec4<float, P> const & b)
		{
			tvec4<float, P> Result(uninitialize);
			Result.data = _mm_div_ps(a.data, b.data);
			return Result;
		}
	};

	template <>
	struct compute_vec4_div<float, lowp>
	{
		static tvec4<float, lowp> call(tvec4<float, lowp> const & a, tvec4<float, lowp> const & b)
		{
			tvec4<float, lowp> Result(uninitialize);
			Result.data = _mm_mul_ps(a.data, _mm_rcp_ps(b.data));
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_and<int32, P>
	{
		static tvec4<int32, P> call(tvec4<int32, P> const& a, tvec4<int32, P> const& b)
		{
			tvec4<int32, P> Result(uninitialize);
			Result.data = _mm_and_si128(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_and<uint32, P>
	{
		static tvec4<uint32, P> call(tvec4<uint32, P> const& a, tvec4<uint32, P> const& b)
		{
			tvec4<uint32, P> Result(uninitialize);
			Result.data = _mm_and_si128(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_or<int32, P>
	{
		static tvec4<int32, P> call(tvec4<int32, P> const& a, tvec4<int32, P> const& b)
		{
			tvec4<int32, P> Result(uninitialize);
			Result.data = _mm_or_si128(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_or<uint32, P>
	{
		static tvec4<uint32, P> call(tvec4<uint32, P> const& a, tvec4<uint32, P> const& b)
		{
			tvec4<uint32, P> Result(uninitialize);
			Result.data = _mm_or_si128(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_xor<int32, P>
	{
		static tvec4<int32, P> call(tvec4<int32, P> const& a, tvec4<int32, P> const& b)
		{
			tvec4<int32, P> Result(uninitialize);
			Result.data = _mm_xor_si128(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_xor<uint32, P>
	{
		static tvec4<uint32, P> call(tvec4<uint32, P> const& a, tvec4<uint32, P> const& b)
		{
			tvec4<uint32, P> Result(uninitialize);
			Result.data = _mm_xor_si128(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_shift_left<int32, P>
	{
		static tvec4<int32, P> call(tvec4<int32, P> const& a, tvec4<int32, P> const& b)
		{
			tvec4<int32, P> Result(uninitialize);
			Result.data = _mm_sll_epi32(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_shift_left<uint32, P>
	{
		static tvec4<uint32, P> call(tvec4<uint32, P> const& a, tvec4<uint32, P> const& b)
		{
			tvec4<uint32, P> Result(uninitialize);
			Result.data = _mm_sll_epi32(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_shift_right<int32, P>
	{
		static tvec4<int32, P> call(tvec4<int32, P> const& a, tvec4<int32, P> const& b)
		{
			tvec4<int32, P> Result(uninitialize);
			Result.data = _mm_srl_epi32(a.data, b.data);
			return Result;
		}
	};

	template <precision P>
	struct compute_vec4_shift_right<uint32, P>
	{
		static tvec4<uint32, P> call(tvec4<uint32, P> const& a, tvec4<uint32, P> const& b)
		{
			tvec4<uint32, P> Result(uninitialize);
			Result.data = _mm_srl_epi32(a.data, b.data);
			return Result;
		}
	};
/*
	template <precision P>
	struct compute_vec4_equal<float, P>
	{
		static bool call(tvec4<float, P> const & a, tvec4<float, P> const & b)
		{
			return _mm_movemask_ps(_mm_cmpeq_ps(a.data, b.data)) == 0x0F;
		}
	};
	
	template <precision P>
	struct compute_vec4_equal<int32, P>
	{
		static bool call(tvec4<int32, P> const & a, tvec4<int32, P> const & b)
		{
			return _mm_movemask_ps(_mm_castsi128_ps(_mm_cmpeq_epi32(a.data, b.data))) == 0x0F;
		}
	};
	
	template <precision P>
	struct compute_vec4_equal<uint32, P>
	{
		static bool call(tvec4<uint32, P> const & a, tvec4<uint32, P> const & b)
		{
			return _mm_movemask_ps(_mm_castsi128_ps(_mm_cmpeq_epi32(a.data, b.data))) == 0x0F;
		}
	};
	
	template <precision P>
	struct compute_vec4_nequal<float, P>
	{
		static bool call(tvec4<float, P> const & a, tvec4<float, P> const & b)
		{
			return _mm_movemask_ps(_mm_cmpeq_ps(a.data, b.data)) != 0;
		}
	};
	
	template <precision P>
	struct compute_vec4_nequal<int32, P>
	{
		static bool call(tvec4<int32, P> const & a, tvec4<int32, P> const & b)
		{
			return _mm_movemask_ps(_mm_castsi128_ps(_mm_cmpeq_epi32(a.data, b.data))) != 0;
		}
	};
	
	template <precision P>
	struct compute_vec4_nequal<uint32, P>
	{
		static bool call(tvec4<uint32, P> const & a, tvec4<uint32, P> const & b)
		{
			return _mm_movemask_ps(_mm_castsi128_ps(_mm_cmpeq_epi32(a.data, b.data))) != 0;
		}
	};
*/
}//namespace detail

#	if !GLM_HAS_DEFAULTED_FUNCTIONS
		template <>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR_CTOR tvec4<float, simd>::tvec4()
#			ifndef GLM_FORCE_NO_CTOR_INIT
				: data(_mm_setzero_ps())
#			endif
		{}
#	endif//!GLM_HAS_DEFAULTED_FUNCTIONS

	template <>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_SIMD tvec4<float, lowp>::tvec4(float s) :
		data(_mm_set1_ps(s))
	{}

	template <>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_SIMD tvec4<float, mediump>::tvec4(float s) :
		data(_mm_set1_ps(s))
	{}

	template <>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_SIMD tvec4<float, highp>::tvec4(float s) :
		data(_mm_set1_ps(s))
	{}

	template <>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_SIMD tvec4<float, lowp>::tvec4(float a, float b, float c, float d) :
		data(_mm_set_ps(d, c, b, a))
	{}

	template <>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_SIMD tvec4<float, mediump>::tvec4(float a, float b, float c, float d) :
		data(_mm_set_ps(d, c, b, a))
	{}

	template <>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR_SIMD tvec4<float, highp>::tvec4(float a, float b, float c, float d) :
		data(_mm_set_ps(d, c, b, a))
	{}
}//namespace glm

#endif//GLM_ARCH & GLM_ARCH_SSE2