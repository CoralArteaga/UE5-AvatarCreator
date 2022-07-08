// Copyright © 2021++ Ready Player Me

#include "ReadyPlayerMeWebBrowser.h"

void UReadyPlayerMeWebBrowser::SetupBrowser(FReadyPlayerWebBrowserResponse webBrowserCallback)
{
	UReadyPlayerMeWebBrowser::BindBrowserToObject();
	webLinkObject->SetAvatarUrlCallback(webBrowserCallback);
	this->ExecuteJavascript(UReadyPlayerMeWebBrowser::javascriptSnippet);
}

UWebLink* UReadyPlayerMeWebBrowser::BindBrowserToObject()
{
	if (!UReadyPlayerMeWebBrowser::webLinkObject) {
		UReadyPlayerMeWebBrowser::webLinkObject = NewObject<UWebLink>(UWebLink::StaticClass());
		webLinkObject->Rename(*UReadyPlayerMeWebBrowser::linkObjectName);
	}
	WebBrowserWidget->BindUObject(UReadyPlayerMeWebBrowser::linkObjectName, webLinkObject, true);
	return webLinkObject;
}
