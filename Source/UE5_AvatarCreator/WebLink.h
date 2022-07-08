// Copyright © 2021++ Ready Player Me

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WebLink.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FReadyPlayerWebBrowserResponse, const FString&, AvatarUrl);
UCLASS()
class UE5_AVATARCREATOR_API UWebLink : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Ready Player Me")
		void AvatarGenerated(FString jsonResponse);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RPM Set Callback"), Category = "Ready Player Me")
		void SetAvatarUrlCallback(FReadyPlayerWebBrowserResponse webBrowserCallback);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RPM Get Last Avatar Url"), Category = "Ready Player Me")
		FString GetLastAvatarUrl();

private:

	FReadyPlayerWebBrowserResponse WebBrowserResponse;
	FString lastAvatarUrl;
};
