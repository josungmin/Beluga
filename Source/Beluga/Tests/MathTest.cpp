#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{
	FVector testVec(1.0, 2.0, 3.0);

	{
		FVector vec(1.0, 2.0, 3.0);

		// Vector의 모든 요소가 허용된 오차(tolerance) 내에서 동일한지 판별
		TestTrue("Vector's all components not equal", vec.AllComponentsEqual(2));
		TestTrue("Vector's all components not equal", vec.IsUniform(2));
	}

	{
		FVector vec(1.0, 2.0, 3.0);

		// 두 Vector의 모든 요소를 비교하여 허용된 오차(tolerance) 내에서 동일한지 판별
		TestTrue("Both vector's all components not equal", vec.Equals(FVector(4, 5, 6), 3));
	}

	{
		FVector vec1(1.0, 1.0, 1.0);
		FVector vec2(2.0, 2.0, 2.0);

		// 두 점 사이의 거리를 반환 
		//TestEqual("The distance between the two points not 3", FVector::Dist(vec1, vec2), 3);
	}

	{
		// Vector의 각 구성 요소의 절대값이 포함된 이 벡터의 복사본을 반환
		FVector vec = FVector(-1.0, -2.0, -3.0).GetAbs(); // float GetAbsMin(), float GetAbsMax()
		TestTrue("Vector not (1, 2, 3)", vec.X == 1 && vec.Y == 2 && vec.Z == 3);
	}

	{
		FVector vec = FVector(0.0, 0.0, 0.0);

		// Vector의 모든 구성 요소가 '정확히' 0 인지 판별
		TestTrue("Vector's all components not zero", vec.IsZero()); // bool IsNearlyZero(float Tolerance)
	}

	{
		// 연산자
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

		// Rotator의 각 컴포넌트에 값을 더한다.
		TestEqual("FRotator not (70, 70, 70)", rot.Add(40, 40, 40), FRotator(70.0, 70.0, 70.0));
	}

	{
		FRotator rot(830.0, 830.0, 830.0);

		// [0, 360] 범위에 속하도록 Rotator 값을 반환
		TestEqual("FRotator not (110, 110, 110)", rot.Clamp(), FRotator(110.0, 110.0, 110.0));
	}

	{
		FRotator rot(30.0, 30.0, 30.0);

		// Rotator의 모든 요소가 허용된 오차(tolerance) 내에서 동일한지 판별
		TestTrue("Rotator's all components not equal", rot.Equals(FRotator(32.0, 32.0, 32.0), 3.0));
	}

	{
		FRotator rot(0.0, 0.0, 0.0);

		// Rotator의 모든 구성 요소가 '정확히' 0 인지 판별
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

		// transform 초기화
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