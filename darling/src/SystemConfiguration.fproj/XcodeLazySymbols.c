#include "SCDynamicStoreKey.h"
#include "SCNetworkConfiguration.h"
#include "SCNetworkConnection.h"

CFStringRef SCDynamicStoreKeyCreateNetworkServiceEntity(CFAllocatorRef allocator,
																 CFStringRef domain,
																 CFStringRef serviceID,
																 CFStringRef entity)
{
	if (!domain || !serviceID) return NULL;
	if (entity)
		return CFStringCreateWithFormat(allocator, NULL,
										 CFSTR("%@/Network/Service/%@/%@"),
										 domain, serviceID, entity);
	return CFStringCreateWithFormat(allocator, NULL,
									 CFSTR("%@/Network/Service/%@"), domain, serviceID);
}

SCNetworkConnectionStatus SCNetworkConnectionGetStatus(SCNetworkConnectionRef connection)
{
	return connection ? kSCNetworkConnectionDisconnected : kSCNetworkConnectionInvalid;
}

CFArrayRef SCNetworkInterfaceCopyAll(void)
{
	return CFArrayCreate(kCFAllocatorDefault, NULL, 0, &kCFTypeArrayCallBacks);
}

CFStringRef SCNetworkInterfaceGetBSDName(SCNetworkInterfaceRef interface)
{
	(void)interface;
	return NULL;
}

CFStringRef SCNetworkInterfaceGetLocalizedDisplayName(SCNetworkInterfaceRef interface)
{
	(void)interface;
	return NULL;
}
