#include "abstractclient.h"
#include "abstractclientbackend.h"

namespace NexusComm {

AbstractClient::AbstractClient(AbstractClientBackend* backend) {
    if(!backend)
        throw "Invalid Backend Passed";
    backend->ref.ref();
    _acb = backend;
}

AbstractClient::~AbstractClient() {
    if(!_acb->ref.deref())
        delete _acb;
}

}
