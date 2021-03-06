/******************************************************************************
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * iSulad licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *     http://license.coscl.org.cn/MulanPSL
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v1 for more details.
 * Author: wujing
 * Create: 2020-02-14
 * Description: provide namespace mock
 ******************************************************************************/

#include "namespace_mock.h"

namespace {
MockNamespace *g_namespace_mock = NULL;
}

void MockNamespace_SetMock(MockNamespace* mock)
{
    g_namespace_mock = mock;
}

char *connected_container(const char *mode)
{
    if (g_namespace_mock != nullptr) {
        return g_namespace_mock->ConnectedContainer(mode);
    }
    return nullptr;
}

char *get_share_namespace_path(const char *type, const char *src_path)
{
    if (g_namespace_mock != nullptr) {
        return g_namespace_mock->GetShareNamespacePath(type, src_path);
    }
    return nullptr;
}

char *get_container_process_label(const char *path)
{
    if (g_namespace_mock != nullptr) {
        return g_namespace_mock->GetContainerProcessLabel(path);
    }
    return nullptr;
}
