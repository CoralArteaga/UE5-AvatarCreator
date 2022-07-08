// Copyright © 2021++ Ready Player Me

#pragma once

#include "CoreMinimal.h"
#include "WebBrowser.h"
#include "WebLink.h"
#include "SWebBrowser.h"
#include "ReadyPlayerMeWebBrowser.generated.h"

/**
 * 
 */
UCLASS()
class UE5_AVATARCREATOR_API UReadyPlayerMeWebBrowser : public UWebBrowser
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Setup Browser"), Category = "Ready Player Me|Web Browser")
		void SetupBrowser(FReadyPlayerWebBrowserResponse response);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Bind Browser To Object"), Category = "Ready Player Me|Web Browser")
		UWebLink* BindBrowserToObject();

private:
	UWebLink* webLinkObject;

	const FString linkObjectName = TEXT("rpmlinkobject");
	const FString javascriptSnippet = TEXT("window.addEventListener('message', function(event){ window.ue.rpmlinkobject.avatargenerated(event.data);});");
	
};
