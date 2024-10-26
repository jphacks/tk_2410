import React, { ReactNode } from "react";
import SvgButton from "./SvgButton";
import Sentence from "./Sentence";

interface CardProps {
  date: string;
  image: string;
  text: string;
  // children: ReactNode;
}

const Card: React.FC<CardProps> = ({ date, image, text }) => {
  return (
    <div className="card">
      <img src={image}></img>
      <h2>{date}</h2>
      <Sentence text={text} />
      <SvgButton />
      {/* {children} */}
    </div>
  );
};

export default Card;
