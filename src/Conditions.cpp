#include "Conditions.h"

namespace Conditions
{
	bool ExampleCondition::EvaluateImpl([[maybe_unused]] RE::TESObjectREFR* a_refr,
	                                    [[maybe_unused]] RE::hkbClipGenerator* a_clipGenerator,
										[[maybe_unused]] void* a_subMod) const
	{
		// put your logic here - return true if the condition is met, false otherwise
		return true;
	}

	CompareGraphVariableNiPoint3DotCondition::CompareGraphVariableNiPoint3DotCondition()
	{
		// add components like this in the constructor, in the order you want them to be displayed in the UI, and keep raw pointers to them
		textComponent = static_cast<ITextConditionComponent*>(AddBaseComponent(
			ConditionComponentType::kText, "Graph Variable Name"));
		niPoint3Component = static_cast<INiPoint3ConditionComponent*>(AddBaseComponent(
			ConditionComponentType::kNiPoint3, "NiPoint3 Value"));
		comparisonComponent = static_cast<IComparisonConditionComponent*>(AddBaseComponent(
			ConditionComponentType::kComparison, "Comparison"));
		numericComponent = static_cast<INumericConditionComponent*>(AddBaseComponent(
			ConditionComponentType::kNumeric, "Numeric Value"));
	}

	RE::BSString CompareGraphVariableNiPoint3DotCondition::GetArgument() const
	{
		auto& niPoint3Value = niPoint3Component->GetNiPoint3Value();
		const auto textArgument = textComponent->GetTextValue();
		const auto comparisonArgument = comparisonComponent->GetArgument();
		const auto numericArgument = numericComponent->GetArgument();
		return std::format("{}.Dot({}, {}, {}) {} {}", textArgument.data(), niPoint3Value.x, niPoint3Value.y,
		                   niPoint3Value.z, comparisonArgument.data(), numericArgument.data()).data();
	}

	RE::BSString CompareGraphVariableNiPoint3DotCondition::GetCurrent(RE::TESObjectREFR* a_refr) const
	{
		return std::to_string(GetDotProduct(a_refr)).data();
	}

	bool CompareGraphVariableNiPoint3DotCondition::EvaluateImpl([[maybe_unused]] RE::TESObjectREFR* a_refr,
	                                                            [[maybe_unused]] RE::hkbClipGenerator* a_clipGenerator,
																[[maybe_unused]] void* a_subMod)
	const
	{
		// run your actual condition logic here - return true if the condition is met, false otherwise
		return comparisonComponent->GetComparisonResult(GetDotProduct(a_refr),
		                                                numericComponent->GetNumericValue(a_refr));
	}

	float CompareGraphVariableNiPoint3DotCondition::GetDotProduct(RE::TESObjectREFR* a_refr) const
	{
		RE::NiPoint3 graphVariableValue;
		if (a_refr)
		{
			if (a_refr->GetGraphVariableNiPoint3(textComponent->GetTextValue(), graphVariableValue))
			{
				auto& niPoint3Value = niPoint3Component->GetNiPoint3Value();
				return graphVariableValue.Dot(niPoint3Value);
			}
		}

		return 0.f;
	}
}
