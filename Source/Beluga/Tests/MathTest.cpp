#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{
	FVector testVec(1.0, 2.0, 3.0);
	
	{
		FVector vec(1.0, 2.0, 3.0);

		// Vector�� ��� ��Ұ� ���� ����(tolerance) ������ �������� �Ǻ�
		TestTrue("Vector's all components not equal", vec.AllComponentsEqual(2));
		TestTrue("Vector's all components not equal", vec.IsUniform(2));
	}

	{
		FVector vec(1.0, 2.0, 3.0);

		// �� Vector�� ��� ��Ҹ� ���Ͽ� ���� ����(tolerance) ������ �������� �Ǻ�
		TestTrue("Both vector's all components not equal", vec.Equals(FVector(4, 5, 6), 3));
	}

	{
		FVector vec1(1.0, 1.0, 1.0);
		FVector vec2(2.0, 2.0, 2.0);

		// �� �� ������ �Ÿ��� ��ȯ 
		TestEqual("The distance between the two points not 3", FVector::Dist(vec1, vec2), 3);
	}

	{
		// Vector�� �� ���� ����� ���밪�� ���Ե� �� ������ ���纻�� ��ȯ
		FVector vec = FVector(-1.0, -2.0, -3.0).GetAbs(); // float GetAbsMin(), float GetAbsMax()
		TestTrue("Vector not (1, 2, 3)", vec.X == 1 && vec.Y == 2 && vec.Z == 3);
	}

	{
		FVector vec = FVector(0.0, 0.0, 0.0);

		// ������ ��� ���� ��Ұ� '��Ȯ��' 0 ���� �Ǻ�
		TestTrue("Vector's all components not zero", vec.IsZero()); // bool IsNearlyZero(float Tolerance)
	}
	
	{
		// ������
		TestEqual("FVector not (1, 2, 3)", (FVector(0, 0, 0) + FVector(1, 2, 3)), FVector(1, 2, 3));
		TestTrue("Both vectors do not have the same value.", (FVector(1, 2, 3) == FVector(1, 2, 3)));
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaRotatorTest, "Beluga.Rotator", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaRotatorTest::RunTest(const FString& Parameters)
{
	//FRotator rot(FRotator::ZeroRotator)

	return true;
}