import React from "react";
import { observer } from "mobx-react-lite";
import "./advantage.scss";
import img_advantage1 from './img_advantage1.png';
import img_advantage2 from './img_advantage2.png';
import img_advantage3 from './img_advantage3.png';

const Advantage = () => {

    const advantage_items = [
        {
            img: img_advantage1,
            title: "提升页面加载性能",
            content: "通过离线加载以及预加载等方式，减少网络耗时，提升页面打开速度。"
        },
        {
            img: img_advantage2,
            title: "大促消峰降带宽成本",
            content: "提前配置离线包，下载h5相关资源，能够大幅度降低大促的整点流量峰值。"
        },
        {
            img: img_advantage3,
            title: "内置包解决互动游戏问题",
            content: "采用JDHybrid的离线包预置技术，完成了11个游戏业务的合规改造，且首屏性能提升达50%+。"
        }
    ];

    const Card = ({img, title, content}) => {
        return (
            <>
            <img className="advantage-content-item-container-img" src={img}></img>
            <div className="advantage-content-item-container-title">{title}</div>
            <div className="advantage-content-item-container-content">{content}</div>
            </>
        );
    }; 

    return (
        <>
        <div className="advantage-title-container">
            <div className="advantage-title-container-ch">核心优势</div>
            <div className="advantage-title-container-en">CODE ADVANTAGES</div>
        </div>
        <div className="advantage-content-container">
            {advantage_items.map((item) => {
                console.log({...item});
                return <div className="advantage-content-item-container">
                    <Card {...item}/>
                </div>;
            })}
        </div>
        </>
    );
};

export default observer(Advantage);