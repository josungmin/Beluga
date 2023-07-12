#include "BelugaMinimal.h"

void StringTest()
{
	FString strA(TEXT("strA"));

	// 길이 구하기
	{
		FString str(TEXT("str"));
		int32 LenStr = str.Len();

		check(LenStr == 3);
	}

	// Replace
	{
		FString str(TEXT("min"));
		FString result = str.Replace(TEXT("mi"), TEXT("EX"));
		check(result == TEXT("EXn"));
	}

	// Left
	{
		FString str(TEXT("sungmin"));
		FString out = str.Left(4);
		check(out == TEXT("sung"));
	}

	// Mid
	{
		FString str(TEXT("SungminSungmin"));
		FString out = str.Mid(5, 6);
		check(out == TEXT("minSung"));
	}
}