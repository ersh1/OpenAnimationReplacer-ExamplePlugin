#pragma once

#include "API/OpenAnimationReplacerAPI-Conditions.h"

namespace Conditions
{
	// The bare minimum
	class ExampleCondition : public CustomCondition
	{
	public:
		constexpr static inline std::string_view CONDITION_NAME = "ExampleCondition"sv;

		RE::BSString GetName() const override { return CONDITION_NAME.data(); }
		RE::BSString GetDescription() const override { return "An example condition."sv.data(); }

		// the earliest version of your plugin that provided this condition in its current form
		constexpr REL::Version GetRequiredVersion() const override { return {1, 0, 0}; }

	protected:
		// this is the function with the actual condition logic
		bool EvaluateImpl(RE::TESObjectREFR* a_refr, RE::hkbClipGenerator* a_clipGenerator, void* a_subMod) const override;
	};

	// A more complex example
	class CompareGraphVariableNiPoint3DotCondition : public CustomCondition
	{
	public:
		constexpr static inline std::string_view CONDITION_NAME = "CompareGraphVariableNiPoint3Dot"sv;

		CompareGraphVariableNiPoint3DotCondition();

		RE::BSString GetName() const override { return CONDITION_NAME.data(); }

		RE::BSString GetDescription() const override
		{
			return
				"A complex example condition - calculates the dot product of a NiPoint3 graph variable value and a given NiPoint3 value and compares it with a given float value."sv
				.data();
		}

		// the earliest version of your plugin that provided this condition in its current form
		constexpr REL::Version GetRequiredVersion() const override { return {1, 0, 0}; }

		// this is displayed in the UI in the right column, next to the condition name
		RE::BSString GetArgument() const override;

		// this is displayed in the UI below the condition components while there's a target selected - it's supposed to be the current value of whatever the condition is checking
		RE::BSString GetCurrent(RE::TESObjectREFR* a_refr) const override;

	protected:
		// this is the function with the actual condition logic
		bool EvaluateImpl(RE::TESObjectREFR* a_refr, RE::hkbClipGenerator* a_clipGenerator, void* a_subMod) const override;

		// these are the components that you added in the constructor, keep raw pointers to them
		ITextConditionComponent* textComponent;
		INiPoint3ConditionComponent* niPoint3Component;
		IComparisonConditionComponent* comparisonComponent;
		INumericConditionComponent* numericComponent;

	private:
		float GetDotProduct(RE::TESObjectREFR* a_refr) const;
	};
}
