from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from typing import Optional

from gli_flow.pdk.corner import PVTCorner, DEFAULT_CORNERS


@dataclass
class PDK(ABC):
    name: str
    variant: str = ""
    description: str = ""
    version: str = ""
    vendor: str = ""

    orfs_platform: str = ""
    pdk_root_env: str = "PDK_ROOT"
    pdk_install_dir: str = ""
    volare_pdk_name: str = ""

    default_voltage: float = 1.8

    track_height: int = 0
    metal_layers: list[str] = field(default_factory=list)
    via_layers: list[str] = field(default_factory=list)

    min_temperature: float = -40
    max_temperature: float = 125
    min_voltage: float = 1.62
    max_voltage: float = 1.98

    corners: list[PVTCorner] = field(default_factory=list)

    def __post_init__(self):
        if not self.corners:
            self.corners = DEFAULT_CORNERS.get(self.name, [
                PVTCorner.worst(), PVTCorner.typical(), PVTCorner.best(),
            ])

    @property
    def platform_dir(self) -> str:
        return self.orfs_platform

    def get_corner(self, name: str) -> Optional[PVTCorner]:
        for c in self.corners:
            if c.name == name:
                return c
        return None

    def worst_corner(self) -> PVTCorner:
        for c in self.corners:
            if c.is_worst:
                return c
        return self.corners[0] if self.corners else PVTCorner.worst()

    def typical_corner(self) -> PVTCorner:
        for c in self.corners:
            if c.is_typical:
                return c
        return self.corners[1] if len(self.corners) > 1 else PVTCorner.typical()

    def lib_dir(self, corner: PVTCorner) -> str:
        return f"{self.pdk_install_dir}/{self.variant}/libs.ref/lib/{self.lib_set(corner)}"

    def lef_dir(self) -> str:
        return f"{self.pdk_install_dir}/{self.variant}/libs.ref/lef"

    @abstractmethod
    def lib_set(self, corner: PVTCorner) -> str:
        ...

    @abstractmethod
    def generate_config_mk(self, design_name: str, corner: PVTCorner) -> str:
        ...

    def to_dict(self) -> dict:
        return {
            "name": self.name,
            "variant": self.variant,
            "description": self.description,
            "version": self.version,
            "vendor": self.vendor,
            "orfs_platform": self.orfs_platform,
            "metal_layers": self.metal_layers,
            "via_layers": self.via_layers,
            "corners": [c.to_dict() for c in self.corners],
        }
