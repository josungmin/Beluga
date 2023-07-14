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
		//TestEqual("The distance between the two points not 3", FVector::Dist(vec1, vec2), 3);
	}

	{
		// Vector�� �� ���� ����� ���밪�� ���Ե� �� ������ ���纻�� ��ȯ
		FVector vec = FVector(-1.0, -2.0, -3.0).GetAbs(); // float GetAbsMin(), float GetAbsMax()
		TestTrue("Vector not (1, 2, 3)", vec.X == 1 && vec.Y == 2 && vec.Z == 3);
	}

	{
		FVector vec = FVector(0.0, 0.0, 0.0);

		// Vector�� ��� ���� ��Ұ� '��Ȯ��' 0 ���� �Ǻ�
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
	{
		FRotator rot(30.0, 30.0, 30.0);

		// Rotator�� �� ������Ʈ�� ���� ���Ѵ�.
		TestEqual("FRotator not (70, 70, 70)", rot.Add(40, 40, 40), FRotator(70.0, 70.0, 70.0));
	}

	{
		FRotator rot(830.0, 830.0, 830.0);

		// [0, 360] ������ ���ϵ��� Rotator ���� ��ȯ
		TestEqual("FRotator not (110, 110, 110)", rot.Clamp(), FRotator(110.0, 110.0, 110.0));
	}

	{
		FRotator rot(30.0, 30.0, 30.0);

		// Rotator�� ��� ��Ұ� ���� ����(tolerance) ������ �������� �Ǻ�
		TestTrue("Rotator's all components not equal", rot.Equals(FRotator(32.0, 32.0, 32.0), 3.0));
	}

	{
		FRotator rot(0.0, 0.0, 0.0);

		// Rotator�� ��� ���� ��Ұ� '��Ȯ��' 0 ���� �Ǻ�
		TestTrue("Rotator's all components not zero", rot.IsZero());
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMatrixTest, "Beluga.Matrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMatrixTest::RunTest(const FString& Parameters)
{
	{
		FMatrix mat1(FMatrix::Identity);
		FMatrix mat2(FMatrix::Identity);

		mat1.M[2][2] = 2;
		mat2.M[2][2] = 4;

		TestTrue("Both matrix equal", mat1 != mat2);
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTransformTest, "Beluga.Transform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTransformTest::RunTest(const FString& Parameters)
{
	{
		FTransform transform;

		// transform �ʱ�ȭ
		transform.SetComponents(FRotator(30.0, 30.0, 30.0).Quaternion(), FVector(10.0, 20.0, 30.0), FVector(1.0, 1.0, 1.0));

		// GetRotation()
		TestEqual("Quat not (30.0, 30.0, 30.0)", transform.GetRotation(), FRotator(30.0, 30.0, 30.0).Quaternion());

		// GetTranslation
		TestEqual("Translation not (10.0, 20.0, 30.0)", transform.GetLocation(), FVector(10.0, 20.0, 30.0));

		// Get Scale3D
		TestEqual("Scale3D not (1.0, 1.0, 1.0)", transform.GetScale3D(), FVector(1.0, 1.0, 1.0));
	}

	return true;
}