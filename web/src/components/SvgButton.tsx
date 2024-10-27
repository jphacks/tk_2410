import type React from "react";
import "./SvgButton.css";

const SvgButton: React.FC = () => {
  return (
    <a href="/novel" className="btn btn-svg">
      <svg width="200" height="50" role="img">
        <title>SvgButton</title>
        <rect x="2" y="2" rx="0" width="200" height="50" fill="none" />
      </svg>
      <span>PUSH！</span>
    </a>
  );
};

export default SvgButton;
