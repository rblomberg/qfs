//---------------------------------------------------------- -*- Mode: C++ -*-
// $Id$
//
// Created 2007/01/17
// Author: Sriram Rao
//
// Copyright 2008-2012 Quantcast Corp.
// Copyright 2007-2008 Kosmix Corp.
//
// This file is part of Kosmos File System (KFS).
//
// Licensed under the Apache License, Version 2.0
// (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.
//
// \brief Code to deal with chunk re-replication and recovery.
//----------------------------------------------------------------------------

#ifndef CHUNKSERVER_REPLICATOR_H
#define CHUNKSERVER_REPLICATOR_H

#include <stdint.h>

namespace KFS
{

struct ReplicateChunkOp;
class Properties;

class Replicator
{
public:
    struct Counters
    {
        typedef int64_t Counter;

        Counter mReplicationCount;
        Counter mReplicationErrorCount;
        Counter mReplicationCanceledCount;
        Counter mRecoveryCount;
        Counter mRecoveryErrorCount;
        Counter mRecoveryCanceledCount;
        Counter mReplicatorCount;
        Counters()
            : mReplicationCount(0),
              mReplicationErrorCount(0),
              mReplicationCanceledCount(0),
              mRecoveryCount(0),
              mRecoveryErrorCount(0),
              mRecoveryCanceledCount(0),
              mReplicatorCount(0)
            {}
        void Reset()
            { *this = Counters(); }
    };
    static void Run(ReplicateChunkOp* op);
    static int GetNumReplications();
    static void CancelAll();
    static void SetParameters(const Properties& props);
    static void GetCounters(Counters& counters);
};

}

#endif // CHUNKSERVER_REPLICATOR_H
