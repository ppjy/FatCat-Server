#ifndef PLAYERLOGIN_H
#define PLAYERLOGIN_H

#include "NetWork/tcpconnection.h"
#include "Game/postgresqlstruct.h"


class PlayerLogin
{
public:
    PlayerLogin();
    ~PlayerLogin();

    //保存玩家角色退出数据，并发送下线通知给其他玩家
    void SavePlayerOfflineData(TCPConnection::Pointer conn);

    //注册用户名
    void RegisterUserID(TCPConnection::Pointer conn, STR_PlayerRegisterUserId *reg);

    //注册角色，该函数必须在用户名已注册的情况下调用
    void RegisterRole(TCPConnection::Pointer conn, STR_PlayerRegisterRole *reg);

    //删除角色
    void DeleteRole(TCPConnection::Pointer conn, hf_uint32 roleid);

    //登陆帐号,并保存用户会话
    void LoginUserId(TCPConnection::Pointer conn, STR_PlayerLoginUserId *reg);

    //角色登陆
    void LoginRole(TCPConnection::Pointer conn, hf_uint32 roleid);

    //用户下线，发送下线通知给其他玩家，保存改用户的相关信息，断开sock连结
    void PlayerOffline(TCPConnection::Pointer conn, STR_PackPlayerOffline *reg);

    //好友下线
    void FriendOffline(TCPConnection::Pointer conn);

    //玩家这些属性变化，实时写进数据库
    //更新玩家金钱
    static void UpdatePlayerMoney(UpdateMoney* upMoney);
    //更新玩家等级
    static void UpdatePlayerLevel(UpdateLevel* upLevel);
    //更新玩家经验
    static void UpdatePlayerExp(UpdateExp* upExp);
    //更新玩家物品数量
    static void UpdatePlayerGoods(hf_uint32 roleid, STR_Goods* upGoods);
    //新物品更新背包
    static void InsertPlayerGoods(hf_uint32 roleid, STR_Goods* insGoods);
    //删除玩家背包物品
    static void DeletePlayerGoods(hf_uint32 roleid, hf_uint16 Pos);
    //更新玩家装备属性
    static void UpdatePlayerEquAttr(hf_uint32 roleid, STR_Equipment* upEquAttr);
    //新装备更新属性
    static void InsertPlayerEquAttr(hf_uint32 roleid, STR_Equipment* insEquAttr);
    //删除玩家背包装备属性
    static void DeletePlayerEquAttr(hf_uint32 roleid, hf_uint32 equid);
    //更新玩家任务进度
    static void UpdatePlayerTask(hf_uint32 roleid, STR_TaskProcess* upTask);
    //插入新任务
    static void InsertPlayerTask(hf_uint32 roleid, STR_TaskProcess* insTask);
    //删除任务
    static void DeletePlayerTask(hf_uint32 roleid, hf_uint32 taskid);


    //玩家上线
    //发送角色列表
    void SendRoleList(TCPConnection::Pointer conn, hf_char* userID);
    //发送好友列表
    void SendFriendList(TCPConnection::Pointer conn, hf_uint32 RoleID);

    //发送玩家可视范围内的玩家
    void SendViewRole(TCPConnection::Pointer conn);

    //发送角色经验，属性

    //发送角色背包里的物品
    void SendRoleGoods(TCPConnection::Pointer conn, hf_uint32 RoleID);
    //发送角色背包里装备的属性
    void SendRoleEquAttr(TCPConnection::Pointer conn, hf_uint32 RoleID);
    //发送角色金币
    void SendRoleMoney(TCPConnection::Pointer conn, hf_uint32 RoleID);
    //查询玩家未捡取的物品
    void SendRoleNotPickGoods(TCPConnection::Pointer conn, hf_uint32 RoleID);


    //玩家下线
    //用户下线删除保存的对应的<name，sock>
    void DeleteNameSock(TCPConnection::Pointer conn);
    //用户下线删除保存的对应的<nick, sock>
    void DeleteNickSock(TCPConnection::Pointer conn);
    //将玩家任务进度写进数据库
    void SaveRoleTaskProcess(TCPConnection::Pointer conn);
    //将玩家背包里的物品写进数据库
    void SaveRoleBagGoods(TCPConnection::Pointer conn);
    //将玩家装备属性写进数据库
    void SaveRoleEquAttr(TCPConnection::Pointer conn);
    //将玩家金钱写进数据库
    void SaveRoleMoney(TCPConnection::Pointer conn);
    //将下线消息通知给可视范围内的玩家
    void SendOffLineToViewRole(TCPConnection::Pointer conn);
    //保存玩家未捡取的物品
    void SaveRoleNotPickGoods(TCPConnection::Pointer conn);

    //判断两个玩家能否看到
    hf_uint8 caculateDistanceWithRole(STR_PackPlayerPosition* pos1, STR_PackPlayerPosition* pos2);

};

#endif // PLAYERLOGIN_H
